#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int ans = 0, a = 1, b = 1;

bool valid(int x, int y) {
    return (0 <= x) && (x < b) && (0 <= y) && (y < a);
}

void DFS(int x, int y, vector<vector<bool> > &arr) {
    if (valid(x, y) && !arr[x][y]) {
        arr[x][y] = true;
        ans++;
        DFS(x + 1, y, arr);
        DFS(x - 1, y, arr);
        DFS(x, y - 1, arr);
        DFS(x, y + 1, arr);

    } else {
        return;
    }
}


int main() {
    int x, y;
    while (true) {
        cin >> a >> b;
        if(a==0 && b==0){
            return 0;
        }
        vector<vector<bool> > arr;
        for (int i = 0; i < b; ++i) {
            vector<bool> add;
            for (int j = 0; j < a; ++j) {
                char s;
                cin >> s;
                if (s == '@') {
                    x = i;
                    y = j;
                    add.push_back(false);
                } else if (s == '_') {
                    add.push_back(false);
                } else {
                    add.push_back(true);
                }
            }
            arr.push_back(add);
        }
        DFS(x, y, arr);
        cout << ans << endl;
    }
}