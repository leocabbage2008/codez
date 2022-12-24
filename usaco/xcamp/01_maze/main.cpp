#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char grid[n][n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j) cin >> grid[i][j];
    }
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a-=1;
        b-=1;
        //unsolved
    }
}
