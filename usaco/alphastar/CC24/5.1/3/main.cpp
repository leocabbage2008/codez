#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int N;
bool p[50][50];

int check1(bool pasture[N][N]) {
    bool clear = true;
    int counter = 0;
    for (int i = 1; i < N; ++i) {
        if (pasture[0][i]) {
            clear = false;
            break;
        }
    }
    if (clear) {
        for (int i = 0, k = N - 2; i < N - 1; ++i) {
            if (pasture[i][k]) {
                clear = false;
                break;
            }
        }
    }
    if (clear) counter++;
    clear = true;
    for (int i = 1, k = N - 1; i < N; ++i) {
        if (pasture[k][i]) {
            clear = false;
            break;
        }
    }
    if (clear) {
        for (int i = 1; i < N; ++i) {
            if (pasture[0][i]) {
                clear = false;
                break;
            }
        }
    }
    if (clear) counter++;
    return counter;
}

int check2(bool pasture[N][N]) {
    int counter = 0;
    for (int turn_i = 1; turn_i < N - 2; ++turn_i) {
        bool clear = true;
        for (int i = 1; i < turn_i; ++i) {
            if (pasture[i][0]) {
                clear = false;
                break;
            }
        }
        if (clear) {
            for (int i = 0; i < N - 1; ++i) {
                if (pasture[turn_i][i]) {
                    clear = false;
                    break;
                }
            }
        }
        if (clear) {
            for (int i = turn_i + 1, k = N - 1; i < N - 2; ++i) {
                if (pasture[i][k]) {
                    clear = false;
                    break;
                }
            }
        }
        if (clear) counter++;
    }
    for (int turn_i = 1; turn_i < N - 2; ++turn_i) {
        bool clear = true;
        for (int i = 1; i < turn_i; ++i) {
            if (pasture[0][i]) {
                clear = false;
                break;
            }
        }
        if (clear) {
            for (int i = 0; i < N - 1; ++i) {
                if (pasture[turn_i][i]) {
                    clear = false;
                    break;
                }
            }
        }
        if (clear) {
            for (int i = turn_i + 1, k = N - 1; i < N - 2; ++i) {
                if (pasture[k][i]) {
                    clear = false;
                    break;
                }
            }
        }
        if (clear) counter++;
    }
    return counter;
}

int check3(bool pasture[N][N]) {
    int counter = 0;
    for (int center_i = 0; center_i < N - 1; ++center_i) {
        for (int center_j = 0; center_j < N - 2; ++center_j) {
            bool clear = true;
            for (int i = 1; i < center_j; ++i) {
                if (pasture[0][i]) {
                    clear = false;
                    break;
                }
            }
            if (clear) {
                for (int i = 1; i < center_i; ++i) {
                    if (pasture[i][center_j]) {
                        clear = false;
                        break;
                    }
                }
            }
            if (clear) {
                for (int i = center_j + 1; i < N; ++i) {
                    if (pasture[center_i][i]) {
                        clear = false;
                        break;
                    }
                }
            }
            if (clear) {
                for (int i = center_i + 1, k = N - 1; i < N - 1; ++i) {
                    if (pasture[i][k]) {
                        clear = false;
                        break;
                    }
                }
            }
            if (clear)counter++;
        }
    }
    for (int center_i = 0; center_i < N - 1; ++center_i) {
        for (int center_j = 0; center_j < N - 2; ++center_j) {
            bool clear = true;
            for (int i = 1; i < center_j; ++i) {
                if (pasture[i][0]) {
                    clear = false;
                    break;
                }
            }
            if (clear) {
                for (int i = 1; i < center_i; ++i) {
                    if (pasture[center_j][i]) {
                        clear = false;
                        break;
                    }
                }
            }
            if (clear) {
                for (int i = center_j + 1; i < N; ++i) {
                    if (pasture[i][center_i]) {
                        clear = false;
                        break;
                    }
                }
            }
            if (clear) {
                for (int i = center_i + 1, k = N - 1; i < N - 1; ++i) {
                    if (pasture[k][i]) {
                        clear = false;
                        break;
                    }
                }
            }
            if (clear)counter++;
        }
    }
    return counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int K;
        cin >> N >> K;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                char c;
                cin >> c;
                if (c == '.') p[i][j] = false;
                else p[i][j] = true;
            }
        }
        int counter = check1(p);
        if (K >= 2) counter += check2(p);
        if (K == 3) counter += check3(p);
        cout << counter << endl;
    }
}