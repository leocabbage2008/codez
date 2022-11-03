#include <fstream>
#include <iostream>

using namespace std;

int r, c;
int m[10][20];

int find(int column, int value) {
    for (int i = 0; i < r; ++i) {
        if (m[column][i] == value) return i;
    }
    return -1;
}

int consistent(int i, int j){
    int t = 0;
    for(int a = 0; a < c; ++a){
        if(find(a, i)>find(a, j)){
            t++;
        }
    }
    return t;
}

int main() {
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
    fin >> c >> r;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            fin >> m[i][j];
        }
    }
    int n = 0;
    for(int a = 1; a<=r; a++){
        for(int b = 1; b<=r; b++){
            if(consistent(a,b)==c) n++;
        }
    }
    fout << n << endl;

}