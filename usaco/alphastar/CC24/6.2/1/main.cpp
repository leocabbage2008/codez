#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;
    int i = 0;
    while (i < N && s[i] == s[i + 1]) {
        //can't change it
        i += 2;
    }
    if (i == N) {
        //they are all suspicious
        cout << 0;
        return 0;
    }
    int j = i, counter = 0;
    while (true) {
        bool hg = s[i] == 'H' && s[i + 1] == 'G';
        while (j < N && ((s[j] == s[i] && s[j + 1] == s[i + 1]) || s[j] == s[j + 1])) {
            j += 2;
        }
        if (j == N) {
            if (!hg) counter++;
            break;
        }
        counter++;
        i = j;
    }
    cout << counter;

}