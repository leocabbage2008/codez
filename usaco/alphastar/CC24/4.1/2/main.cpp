#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool comfy(int x, int y, bool pasture[1001][1001], int adjacent[1001][1001]) {
    return pasture[x][y] && adjacent[x][y] == 3;
}

int count(int x, int y, int adjacent[1001][1001], bool pasture[1001][1001]) {
    int dx[5] = {-1, 1, 0, 0, 0}, dy[5] = {0, 0, -1, 1, 0};
    int before = 0;
    for (int i = 0; i < 5; ++i) {
        if ((x + dx[i] < 0) || (x + dx[i] > 1000) || (y + dy[i] < 0) ||
            (y + dy[i] > 1000))
            continue;
        if(!pasture[dx[i]+x][dy[i]+y]) continue;
        if (comfy(x + dx[i], y + dy[i], pasture, adjacent))
            before++;
    }
    return before;
}

int main() {
    int N;
    cin >> N;
    bool pasture[1001][1001];
    int adjacent[1001][1001];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j){
            pasture[i][j] = false;
            adjacent[i][j] = 0;
        }
    }
    int dx[5] = {-1, 1, 0, 0, 0}, dy[5] = {0, 0, -1, 1, 0};
    while (N--) {
        int x, y;
        cin >> x >> y;
        int before = count(x,y, adjacent, pasture);
        pasture[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            if ((x + dx[i] < 0) || (x + dx[i] > 1000) || (y + dy[i] < 0) ||
                (y + dy[i] > 1000))
                continue;
adjacent[x+dx[i]][y+dy[i]]        }

    }
}