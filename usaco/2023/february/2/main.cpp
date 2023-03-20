#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int N;
int K;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        bool c[N][N];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                char h;
                cin >> h;
                c[i][j] = (h == '.');
            }
        }
        cin >> K;
        bool s[N][N];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                char h;
                cin >> h;
                s[i][j] = (h == '.');
            }
        }
        bool covered[N][N];
        for (int i = K; i < N; ++i) {
            for (int j = K; j < N; ++j) {
                bool state = true;
                for (int a = 0; a < K; ++a) {
                    for (int b = 0; b < K; ++b) {
                        for (int x = 0; x < 4; ++x) {
                            if (s[a][b] && !c[a][b]) {
                                state = false;
                                break;
                            }
                            if (s[a][b] && c[a][b]) {
                                covered[a][b] = true;
                            }
                            bool res[K][K];
                            for (int y = 0; y < K; ++y) {
                                for (int z = 0; j < K; ++z) {
                                    res[y][z] = s[z][y];
                                }
                            }
                            for (int y = 0; y < K; ++y) {
                                for (int z = 0; z < K; ++z) {
                                    s[y][z] = res[y][z];
                                }
                            }
                        }
                    }
                    if (!state) break;
                }
            }
        }
        bool state;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (covered[i][j] == c[i][j]) continue;
                state = false;
                break;
            }
        }
        if (state) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}