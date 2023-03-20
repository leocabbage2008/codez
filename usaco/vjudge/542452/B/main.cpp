#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    vector<string> f;
    string s="0";
    while(getline(cin,s)){
        f.push_back(s);
    }
    for(int i = 0; i < f.size(); ++i){
        cout << f[i] << endl;
    }
}