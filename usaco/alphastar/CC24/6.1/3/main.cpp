#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    string blocks[4];
    for (int i = 0; i < 4; ++i) cin >> blocks[i];

    vector<string> possible;
    bool used[4] = {false};
    for (int i = 0; i < 4; ++i) {
        used[i] = true;
        for (int j = 0; j < 4; ++j) {
            if (used[j]) continue;
            used[j] = true;
            for (int k = 0; k < 4; ++k) {
                if (used[k]) continue;
                used[k] = true;
                for (int l = 0; l < 4; ++l) {
                    if (used[l]) continue;
                    used[l] = true;
                    for (int l1 = 0; l1 < 6; ++l1) {
                        for (int l2 = 0; l2 < 6; ++l2) {
                            for (int l3 = 0; l3 < 6; ++l3) {
                                for (int l4 = 0; l4 < 6; ++l4) {
                                    string word =
                                            ("" + blocks[i][l1]) + blocks[j][l2] + blocks[k][l3] +
                                            blocks[l][l4];
                                    possible.push_back(word.substr(0, 1));
                                    possible.push_back(word.substr(0, 2));
                                    possible.push_back(word.substr(0, 3));
                                    possible.push_back(word.substr(0, 4));
                                }
                            }
                        }
                    }
                    used[l] = false;
                }
                used[k] = false;
            }
            used[j] = false;
        }
        used[i] = false;
    }
    for (int i = 0; i < N; ++i) {
        string word;
        bool found = false;
        for (int j = 0; j < possible.size(); ++j) {
            if (possible[j] == word) {
                found = true;
                break;
            }
        }
        if (found)
            cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}