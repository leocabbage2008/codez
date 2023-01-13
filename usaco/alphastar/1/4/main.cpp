#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    char matrix[A][B];
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < B; ++j) cin >> matrix[i][j];
    }
    for (int i = 0; i < A; ++i) {
        for (int b = 0; b < C; ++b) {
            for (int j = 0; j < B; ++j) {
                for (int a = 0; a < C; ++a) {
                    cout << matrix[i][j];
                }
            }
            cout << endl;
        }
    }
}