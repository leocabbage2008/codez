#include <iostream>

using namespace std;

int main() {
    string ans[3], guess[3];
    int green = 0, yellow = 0;
    for (auto &an: ans)
        cin >> an;
    for (auto &gues: guess)
        cin >> gues;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; j++) {
            if (ans[i][j] == guess[i][j]) {
                green++;
                ans[i][j] = '.';
                guess[i][j] = '.';
            }
        }
    }
    for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
            if (ans[x][y] != '.') {
                for (int a = 0; a < 3; ++a) {
                    for (int b = 0; b < 3; ++b) {
                        if (guess[a][b] != '.') {
                            if (b != y && ans[x][y] == guess[a][b]) {
                                yellow++;
                                ans[x][y] = '.';
                                guess[a][b] = '.';
                            }
                        }
                    }
                }
            }
        }
    }

    cout << green << endl << yellow << endl;
}