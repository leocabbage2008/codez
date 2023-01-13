#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    char correct[3][3], guess[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) cin >> correct[i][j];
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) cin >> guess[i][j];
    }
    vector<int> g(26), s(26), green(26);
    int counter = 0;
    for (int i = 0; i < 26; ++i) {
        g[i] = 0;
        s[i] = 0;
        green[i] = 0;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            s[correct[i][j] - 'A']++;
            g[guess[i][j] - 'A']++;
            if (correct[i][j] == guess[i][j]) {
                green[correct[i][j] - 'A']++;
                counter++;
            }
        }
    }
    int yellows = 0;
    for (int i = 0; i < 26; ++i) yellows += min(s[i], g[i]) - green[i];
    cout << counter << endl << yellows;

}