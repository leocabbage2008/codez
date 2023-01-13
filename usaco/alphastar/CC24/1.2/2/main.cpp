#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int b[N - 1], sol[N];
    for (int i = 0; i < N - 1; ++i) cin >> b[i];
    for (int i = 1; i < b[0]; ++i) {
        bool state = true;
        bool state1 = true;
        bool used[N];
        for (int j = 0; j < N; ++j) used[j] = false;
        used[i - 1] = true;
        sol[0] = i;
        for (int j = 1; j < N; ++j) {
            int x = b[j - 1] - sol[j - 1];
            if (1 <= x && x <= N)
                sol[j] = x;
            else {
                state1 = false;
            }
        }
        if (!state1) continue;
        for (int j = 0; j < N; ++j)
            used[sol[j] - 1] = true;
        for (int j = 0; j < N; ++j) {
            if (!used[j]) {
                state = false;
                break;
            }
        }
        if (state) {
            cout << sol[0];
            for (int j = 1; j < N; ++j) cout << " " << sol[j];
            return 0;
        }

    }
}