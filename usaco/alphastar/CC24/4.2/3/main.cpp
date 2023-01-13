#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<vector<int>> count_neighbors(int i, int j, char pasture[N][M]){
    int di[4] = {-1,0,1,0};
    int dj[4] = {0,1,0,-1};
    vector<vector<int>> neighbors;
    int counter = 0;
    for(int k = 0; k < 4; ++k){
        if(i+di[k] < 0 || i+di[k] >= N || j+dj[k] < 0 || j+dj[k]>=N) continue;
        if(pasture[i+di[k]][j+dj[k]] == 'C'){
            counter++;
          neighbors.push_back({i+di[k],j+dj[k]});
        }
    }
    return {counter,neighbors};
}

int main(){
    cin >> N >> M;
    char pasture[N][M];

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j) cin >> pasture[i][j];
    }

    int counter = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(pasture[i][j]='.') continue;
            vector<vector<int>> neighbors = count_neighbors(i,j,pasture);
            if(neighbors>2) counter++;
            else if(neighbors==2) counter++;
        }
    }
}