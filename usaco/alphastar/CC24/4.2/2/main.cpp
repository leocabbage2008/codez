#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N, K;
vector<string, string> is_sorted(string name_i, string name_j, string paper[]){
    int i = 0;
    while(paper[i] != name_i && paper[i] != name_j)
        i++;

    string name = paper[i];
    i++;
    while(true){
        if(paper[i] < paper[i-1]) return {"false",name};
        if(paper[i] == name_i || paper[i] == name_j)
            return {"true",name};
    }
}

int main(){
    cin >> N >> K;

    int names[N];
    for(int i = 0; i < N; ++i) cin >> names[i];

    string papers[K][N];
    for(int i = 0; i < K; ++i){
        for(int j = 0; j < N; ++j) cin >> papers[i][j];
    }

    int sol[N][N];
    for(int i = 0; i < N; ++i) sol[i][i] = 'B';
    for(int i = 0; i < N; ++i){
        for(int j = i+1; j < N; ++j){
            bool known = false;
            for(int k = 0; k < K; ++k){
                tuple<bool, string> sorted = is_sorted(names[i],names[j],papers[k])
            }
        }
    }

}