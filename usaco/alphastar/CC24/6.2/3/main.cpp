#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N;
    int metals[N];
    for (int i = 0; i < N; ++i) cin >> metals[i];
    cin >> K;
    vector<int> recipes[N];
    for (int i = 0; i < K; ++i) {
        int L, M;
        cin >> L >> M;
        L--;
        for (int j = 1; j <= M; ++j) {
            int ingred;
            cin >> ingred;
            recipes[L].push_back(ingred);
        }
    }
    int counter = 0;
    while (true) {
        int need[N];
        for (int i = 0; i < N; ++i) {
            need[i] = 0;
        }
        need[N - 1] = 1;
        bool made = true;
        for (int i = N - 1; i >= 0; --i) {
            if (need[i] <= metals[i]) metals[i] -= need[i];
            else if (recipes[i].empty()) {
                made = false;
                break;
            } else {
                for (int j = 0; j < recipes[i].size() - 1; ++j) {
                    need[recipes[i][j]] += need[i] - metals[i];
                }
                metals[i] = 0;
            }
        }
        if (!made) break;
        counter++;
    }
    cout << counter;
}