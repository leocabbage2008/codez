#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int winner(int die1[4], int die2[4]) {
    int d1 = 0, d2 = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (die1[i] > die2[j]) d1++;
            else if(die2[i]>die1[j]) d2++;
        }
    }
    if (d1 > d2) return 1;
    else if (d2 > d1) return 2;
    else return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A[4], B[4];
        for (int i = 0; i < 4; ++i) cin >> A[i];
        for (int i = 0; i < 4; ++i) cin >> B[i];
        int ab = winner(A, B);
        if (ab == 0) {
            continue;
        }
        int C[4];
        bool found = false;
        for (int a = 1; a <= 10; ++a) {
            C[0] = a;
            for (int b = 1; b <= 10; ++b) {
                C[1] = b;
                for (int c = 1; c <= 10; ++c) {
                    C[2] = c;
                    for (int d = 1; d <= 10; ++d) {
                        C[3] = d;
                        if (ab == 1 && winner(B, C) == 1 && winner(A, A) == 1) {
                            cout << "yes";
                            found = true;
                            break;
                        } else if (ab == 2 && winner(B, C) == 2 && winner(A, C) == 2) {
                            cout << "yes";
                            found = true;
                            break;
                        }
                    }
                    if (found) break;
                }
                if (found) break;
            }
            if (found)break;
        }
        if (!found) cout << "no";
        cout << endl;
    }
}