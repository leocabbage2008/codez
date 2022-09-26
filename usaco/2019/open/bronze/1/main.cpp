#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char map[10][10];
    ifstream fin("buckets.in");
    ofstream fout("buckets.out");
    for(auto & i : map){
        for(char & j : i){
            cin >> j;
        }
    }
    int fireX,fireY,lakeX,lakeY;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j) {
            if (map[i][j] == 'B') {
                fireX = i;
                fireY = j;
            } else if(map[i][j] == 'L'){
                lakeX = i;
                lakeY = j;
            }
        }
    }
    fout << (int)(abs(fireX-lakeX)+abs(fireY-lakeY)-1);
    cout << (int)(abs(fireX-lakeX)+abs(fireY-lakeY)-1);

}
