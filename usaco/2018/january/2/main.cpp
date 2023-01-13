#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    int N, sum = 0;
    fin >> N;
    int shift[N][2], m = 1000;
    for (int i = 0; i < N; ++i) fin >> shift[i][0] >> shift[i][1];
    int covered[1000] = {0};
    for (int i = 0; i < N; ++i) {
        for (int j = shift[i][0] - 1; j < shift[i][1] - 1; ++j) {
            covered[j]++;
        }
    }
    for(int i : covered){
        if(i!=0) sum++;
    }
    for (int i = 0; i < N; ++i) {
        int alone = 0;
        for (int j = shift[i][0] - 1; j < shift[i][1] - 1; ++j) {
            cout << covered[j] << " ";
            if (covered[j] == 1) alone++;
        }
        m = min(m, alone);
    }
    fout << sum - m;
}