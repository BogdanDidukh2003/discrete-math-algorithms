#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter number 'n' of {1,2,..n}: " << endl;
    cin >> n;

    int block[n + 1];
    int previous[n + 1];
    int next[n + 1];
    bool forward[n + 1];

    for (int i = 1; i <= n; ++i) {
        block[i] = 1;
        forward[i] = true;
    }
    next[1] = 0;

    for (int i = 1; i <= n; ++i) {
        cout << block[i] << " ";
    }
    cout << endl;

    int j = n;
    while (j > 1) {
        int k = block[j];
        if (forward[j]) {
            if (next[k] == 0) {
                next[k] = j;
                previous[j] = k;
                next[j] = 0;
            }
            if (next[k] > j) {
                previous[j] = k;
                next[j] = next[k];
                previous[next[j]] = j;
                next[k] = j;
            }
            block[j] = next[k];
        } else {
            block[j] = previous[k];
            if (k == j) {
                if (next[k] == 0) {
                    next[previous[k]] = 0;
                } else {
                    next[previous[k]] = next[k];
                    previous[next[k]] = previous[k];
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << block[i] << " ";
        }
        cout << endl;
        j = n;
        while (j > 1 && ((forward[j] && block[j] == j)
                         || (!forward[j] && block[j] == 1))) {
            forward[j] = !forward[j];
            j--;
        }
    }

    return 0;
}
