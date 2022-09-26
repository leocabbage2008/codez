#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("promote.in");
    ofstream fout("promote.out");
    int ni[8], d[4], m[4][3]={{0}};
    for(int &i : ni) fin >> i;
    for(int i = 0; i < 4; ++i){
        d[i]=ni[2*i+1]-ni[2*i];
    }
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < i; ++j) m[i][j]=d[i];
    }
    for(int i = 0; i < 3; ++i){
        int sum = 0;
        for(int j = 0; j < 4; ++j){
            sum+=m[j][i];
        }
        fout << sum << endl;
    }
}