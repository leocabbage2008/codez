#include <vector>
#include <fstream>
#include <iostream>;
using namespace std;

int n;

int main() {
    ifstream fin("blocks.in");
    vector<int> alpha(26);
    cout << endl;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        string s0, s1;
        fin >> s0 >> s1;
        for (char j: s0) {
            cout << (int)j-97 << " ";
            if ((int) j - 97 <= 26) {
                alpha[(int) j - 97]++;
            }
        }
        cout << "         ";
        for (char k: s1) {
            cout << (int)k-97 << " ";
            if ((int) k - 97 <= 26) {
                alpha[(int) k - 97]++;
            }
        }
        cout << endl;
    }
    for(int j: alpha){
        cout << j << " ";
    }
    ofstream fout("blocks.out");
    for (int i = 0; i < alpha.size(); ++i) {
        if (i != 0) {
            fout << endl;
        }
        fout << alpha[i];
    }
}