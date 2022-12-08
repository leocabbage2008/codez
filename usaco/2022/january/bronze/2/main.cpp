#include <iostream>

using namespace std;
int N;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int A[4], B[4], a = 0, b = 0;
        for (int j = 0; j < 4; ++j) cin >> A[j];
        for (int j = 0; j < 4; ++j) cin >> B[j];
        for (int x = 0; a < 4; ++a) {
            for (int y = 0; b < 4; ++b) {
                if (A[x] > B[y]) {
                    a++;
                } else if (A[x] == B[y]);
                else b++;
            }
        }
        if (a == 4 || b == 4) {
            cout << "no";
        } else {
            cout << "yes";
        }
        cout << endl;
    }
}
