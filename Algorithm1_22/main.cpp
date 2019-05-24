#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter number 'n': " << endl;
    cin >> n;

    int S[n + 1];
    int R[n + 1];
    int d;

    S[1] = n;
    R[1] = 1;
    d = 1;

    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= R[i]; j++) {
            cout << S[i];
        }
    }
    cout << endl;

    while (S[1] > 1) {
        int sum = 0;
        if (S[d] == 1) {
            sum += R[d];
            d--;
        }
        sum += S[d];
        R[d]--;
        int l = S[d] - 1;
        if (R[d] > 0) {
            d++;
        }
        S[d] = l;
        R[d] = sum / l;
        l = sum % l;
        if (l != 0) {
            d++;
            S[d] = l;
            R[d] = 1;
        }

        for (int i = 1; i <= d; i++) {
            for (int j = 1; j <= R[i]; j++) {
                cout << S[i];
            }
        }
        cout << endl;
    }

    return 0;
}
