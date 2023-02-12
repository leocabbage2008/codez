#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

//int n;
//
//void f(int a, int b, int c, int count) {
//    if (count == n) {
//        cout << c << endl;
//        return;
//    }
//    int d = a + b + c;
//    a = b;
//    b = c;
//    c = d;
//    count++;
//    f(a, b, c, count);
//}
//
//int main() {
//    cin >> n;
//    if(n<=3) cout << 1;
//    else f(1, 1, 1, 3);
//}

//int c = 0, n, m;
//
//void f(int x, int y, vector<vector<char>> &mat) {
//    if (x < 0 || x >= m  || y < 0 || y >= n || mat[y][x] == '#' )
//        return;
//    mat[y][x] = '#';
//    if (x == m - 1 && y == n - 1) {
//        mat[y][x] = '*';
//        c++;
//        return;
//    }
//    f(x + 1, y, mat);
//    f(x - 1, y, mat);
//    f(x, y + 1, mat);
//    f(x, y - 1, mat);
//    mat[y][x] = '*';
//}
//
//int main() {
//    cin >> n >> m;
//    vector<vector<char>> mat;
//    for (int i = 0; i < n; ++i) {
//        vector<char> row;
//        for (int j = 0; j < m; ++j) {
//            char c;
//            cin >> c;
//            row.push_back(c);
//        }
//        mat.push_back(row);
//    }
//    f(0, 0, mat);
//    cout << c;
//}

int n, m, ans = -1;

void f(int x, int y, vector<vector<char>> & orig, vector<vector<char>> &mat, int c) {
    if (x < 0 || x >= m || y < 0 || y >= n || mat[y][x] == '#')
        return;
    else {
        if (mat[y][x] != '*') {
            c += mat[y][x] - '0';
        }
    }
    if (x == m - 1 && y == n - 1) {
        ans = max(c,ans);
        return;
    }
    mat[y][x] = '#';
    f(x + 1, y, orig, mat, c);
    f(x - 1, y, orig, mat, c);
    f(x, y + 1, orig, mat, c);
    f(x, y - 1, orig, mat, c);
    mat[y][x] = orig[y][x];
}

int main() {
    cin >> n >> m;
    vector<vector<char>> mat;
    for (int i = 0; i < n; ++i) {
        vector<char> row;
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            row.push_back(c);
        }
        mat.push_back(row);
    }
    vector<vector<char>> cop;
    cop=mat;
    f(0, 0, cop, mat, 0);
    cout << ans << endl;
}