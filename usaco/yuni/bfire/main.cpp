#include <iostream>
using namespace std;

int main() {
    int N, c = 0, i = 0, d;
    cin >> N;
    int cows[N];
    int visited[N];
    for(int i = 1; i <= N; ++i){
        cows[i]=i;
        visited[i]=0;
    }
    while(!visited[c]){
        d = c;
        visited[d] = true;
        i = (i+d-1)%N+1;
        c=cows[i];
        c++;
        if(c==1) break;
    }
    cout << d;
}
