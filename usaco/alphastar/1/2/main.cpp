#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    //L is the length of the braclet
    //C is the number of charms
    //N is the position of the nail
    int L, C, N;
    cin >> L >> C >> N;
    for(int i = 0; i < C; ++i){
        int a, b;
        cin >> a >> b;
        cout << abs(b-N)+a << endl;
    }

}