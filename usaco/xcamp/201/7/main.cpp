#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, ans = 0;

void filler(int row, int col, vector<vector<bool>> &mat, bool value) {
    mat[row][col] = value;
    for (int i = 0; i < n; ++i) {
        mat[row][i] = value;
        mat[i][col] = value;
    }
    for (int i = 0; i <= row + col; ++i) {
        if (i < n && (row + col - i) < n) {
            mat[i][row + col - i] = value;
        }
    }
    int a = row, b = col;
    while (a != -1 && b != -1) {
        mat[a][b] = value;
        a--;
        b--;
    }
    a = row, b = col;
    while (a != n && b != n) {
        mat[a][b] = value;
        a++;
        b++;
    }
}

void queen(int col, vector<vector<bool>> &mat) {
    if (col == n - 1) {
        ans++;
        return;
    }
    for (int row = 0; row < n; ++row) {
        if (!mat[row][col]) {
            filler(row, col, mat, true);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            queen(col + 1, mat);
            filler(row, col, mat, true);
        }
    }
}

int main() {
    cin >> n;
    vector<vector<bool>> mat;
    for (int i = 0; i < n; ++i) {
        vector<bool> a;
        for (int j = 0; j < n; ++j) {
            a.push_back(false);
        }
        mat.push_back(a);
    }
    queen(0, mat);
    cout << ans;
}