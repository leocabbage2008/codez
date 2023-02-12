#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int N;
int maze[10][10];
vector<int> m;

void f(int x, int y, int n) {
    if (x < 0 || x >= N || y < 0 || y >= N || maze[x][y] == 1)
        return;
    if (x == N - 1 && y == N - 1) {
        m.push_back(n);
        return;
    }
    maze[x][y] = 1;
    f(x + 1, y, n + 1);
    f(x - 1, y, n + 1);
    f(x, y + 1, n + 1);
    f(x, y - 1, n + 1);
    maze[x][y] = 0;
    n--;
}


int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> maze[i][j];
        }
    }
    f(0, 0, 0);
    cout << m.size();
}

