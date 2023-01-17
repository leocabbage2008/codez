#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int ans = 0, N;

bool valid(int x, int y) {
    return (0 <= x) && (x < N) && (0 <= y) && (y < N);
}

void DFS(int x, int y, vector<vector<bool>> arr) {
    if (!arr[x][y]) {
        arr[x][y] = true;
        ans++;
        if (valid(x, y)) {
            DFS(x + 1, y, arr);
            DFS(x - 1, y, arr);
            DFS(x - 1, y - 1, arr);
            DFS(x + 1, y + 1, arr);
        }
    } else {
        return;
    }
}


int main() {
    int x, y;
    cin >> N >> x >> y;
    vector<vector<bool>> arr;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bool s;
            cin >> s;
            arr[i][j] = s;
        }
    }
    DFS(x, y, arr);
}