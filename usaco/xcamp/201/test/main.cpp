#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> sums;

int move(vector<vector<int>> &a, int x, int y) {
    if (y == n - 1 || x == n - 1) {
        return 0;
    }
    cout << x << " " << y << ": " << a[x][y] << endl;
    return a[x][y] + max(move(a, x, y + 1), move(a, x + 1, y + 1));

}

int main() {
    vector<vector<int>> arr(100, vector<int>(101));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> arr[i][j];
        }
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j <= i; ++j) cout << arr[i][j] << " ";
//        cout << endl;
//    }
    cout << move(arr, 0, 0);
}