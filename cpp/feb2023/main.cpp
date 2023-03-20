#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int r, c, co = 0;
    cin >> c >> r;
    char v[c][r];
    for(int i = 0; i < c; ++i){
        for(int j = 0; j < r; ++j){
            cin >> v[i][j];
        }
    }
    for(int i = 0; i < r; ++i){
        bool evil = false;
        for(int j = 0; j < c; ++j){
            if(v[j][i]=='S'){
                evil = true;
                break;
            }
        }
        if(evil) continue;
        for(int j = 0; j < c; ++j){
            v[j][i]='X';
        }
    }
    for(int i = 0; i < c; ++i){
        bool evil = false;
        for(int j = 0; j < r; ++j){
            if(v[i][j]=='S'){
                evil = true;
                break;
            }
        }
        if(evil) continue;
        for(int j = 0; j < r; ++j){
            v[i][j]='X';
        }
    }
    for(int i = 0; i < c; ++i){
        for(int j = 0; j < r; ++j){
            if(v[i][j]=='X') co++;
        }
    }
    cout << co << endl;
//    for(int i = 0; i < c; ++i){
//        for(int j = 0; j < r; ++j) cout << v[i][j] << " ";
//        cout << endl;
//    }
}