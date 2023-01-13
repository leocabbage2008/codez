#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int h[N];
        for (int i = 0; i < N; ++i) cin >> h[i];
        if (N == 1) {
            cout << 0 << endl;
            continue;
        } else if (N == 2) {
            if (h[0] == h[1]) cout << 0 << endl;
            else cout << abs(h[0] - h[1]) << endl;
        }
        int counter = 0;
        for (int i = 0; i < N - 1; ++i) {
            if (h[i] > h[i - 1]) {
                int diff = h[i] - h[i - 1];
                h[i] -= diff;
                h[i + 1] -= diff;
                counter += 2 * diff;
            }
        }
        for (int i = N - 2; i >= 1; ++i) {
            if (h[i] > h[i + 1]) {
                int diff = h[i] - h[i + 1];
                h[i] -= diff;
                h[i - 1] -= diff;
                counter += 2 * diff;
            }
        }

        if (h[0] == h[1] && h[0] >= 0) cout << counter;
        else cout << -1;

    }
}