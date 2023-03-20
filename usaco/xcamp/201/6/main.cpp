#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n, m, ways = 0;
vector<vector<char>> mat;

void hops(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) {
        return;
    }
    if (x == m - 1 && y == n - 1) {
        ways++;
        return;
    }
    for (int i = x+1; i < n; ++i) {
        for (int j = y+1; j < m; ++j) {
//            if (i == y || j == x) continue;
            if (mat[x][y] != mat[i][j]) {
                hops(i, j);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        vector<char> a(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[j];
        }
        mat.push_back(a);
    }
    hops(0, 0);
    cout << ways;
}