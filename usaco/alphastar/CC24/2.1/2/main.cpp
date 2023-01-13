#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, counter = 0;
    cin >> N;
    char correct[N], incorrect[N];
    bool streak = false;
    for(int i = 0; i < N; ++i) cin >> correct[i];
    for(int i = 0; i < N; ++i) cin >> incorrect[i];
    for(int i = 0; i < N; ++i){
        if(correct[i]==incorrect[i]){
            if(streak) counter+=1;
            streak = false;
        }
        else streak = true;
    }
    if(streak) counter+=1;
    cout << counter;
}