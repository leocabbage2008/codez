#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int pos[26];
    for (int i = 0; i < 26; ++i) {
        pos[a[i] - 'a'] = i;
    }

    int counter = 1;
    for(int i = 0; i < b.size()-1; ++i){
        if(pos[b[i+1]-'a'] <= pos[b[i]-'a'])
            counter++;
    }
    cout << counter;
}