#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int winner(vector<int> rules, int play1, int play2){
    int i = 0, j = 0;
    if(play1==play2) return 0;
    for(int a = 0; a < 3; ++a){
        if(rules[a]==play1) i = a;
        if(rules[a]==play2) j = a;
    }
    if(j<i || (i==0 && j==2)){
        return 1;
    } else return 2;
}

int main() {
//    ifstream fin("hps.in");
//    ofstream fout("hps.out");
    int N;
    cin >> N;
    vector<vector<int>> plays(N, vector<int>(2));
    for (int i = 0; i < N; ++i) cin >> plays[i][0] >> plays[i][1];
    vector<int> result(N);
    for(int i = 0; i < N; ++i) result[i] = 0;
    vector<vector<int>> combo;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (i == j || j == k || i == k) continue;
                combo.push_back({i + 1, j + 1, k + 1});
            }
        }
    }
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < N; ++j){
            result[i]+=winner(combo[i],plays[j][0],plays[j][1])%2;
        }
    }
    for(int i : result) cout << i << endl;

}
