#include <iostream>

using namespace std;

int main() {
    int maxNumber;
    cout << "Enter number 'n' of {1,2,..n}: " << endl;
    cin >> maxNumber;

    int block[maxNumber + 1];
    int previousBlock[maxNumber + 1];
    int nextBlock[maxNumber + 1];
    bool forward[maxNumber + 1];
    int activeElement;

    for (int number = 1; number <= maxNumber; number++) {
        block[number] = 1;
        forward[number] = true;
    }
    nextBlock[1] = 0;

    for (int number = 1; number <= maxNumber; ++number) {
        cout << block[number] << " ";
    }
    cout << endl;

    activeElement = maxNumber;
    while (activeElement > 1) {
        int numberOfActiveElementBlock = block[activeElement];
        if (forward[activeElement]) {
            if (nextBlock[numberOfActiveElementBlock] == 0) {
                nextBlock[numberOfActiveElementBlock] = activeElement;
                previousBlock[activeElement] = numberOfActiveElementBlock;
                nextBlock[activeElement] = 0;
            }
            if (nextBlock[numberOfActiveElementBlock] > activeElement) {
                previousBlock[activeElement] = numberOfActiveElementBlock;
                nextBlock[activeElement] = nextBlock[numberOfActiveElementBlock];
                previousBlock[nextBlock[activeElement]] = activeElement;
                nextBlock[numberOfActiveElementBlock] = activeElement;
            }
            block[activeElement] = nextBlock[numberOfActiveElementBlock];
        } else {
            block[activeElement] = previousBlock[numberOfActiveElementBlock];
            if (numberOfActiveElementBlock == activeElement) {
                if (nextBlock[numberOfActiveElementBlock] == 0) {
                    nextBlock[previousBlock[numberOfActiveElementBlock]] = 0;
                } else {
                    nextBlock[previousBlock[numberOfActiveElementBlock]] = nextBlock[numberOfActiveElementBlock];
                    previousBlock[nextBlock[numberOfActiveElementBlock]] = previousBlock[numberOfActiveElementBlock];
                }
            }
        }
        for (int number = 1; number <= maxNumber; number++) {
            cout << block[number] << " ";
        }
        cout << endl;
        activeElement = maxNumber;
        while (activeElement > 1 && ((forward[activeElement] && block[activeElement] == activeElement)
                         || (!forward[activeElement] && block[activeElement] == 1))) {
            forward[activeElement] = !forward[activeElement];
            activeElement--;
        }
    }

    return 0;
}
