#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int needs[N];
    for (int i = 0; i < N; ++i) {
        cin >> needs[i];
    }
    bool streak = false;
    int a = 0, b = 0, ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (!streak) {
            if (((K + 1) + (K + 1)) > (K + needs[i + 1] - needs[i] + 1)) {
                a = needs[i];
                b = needs[i + 1];
                streak = true;
            }
        } else {
            if (((K + 1) + (K + b - a + 1)) < ((K + 1) + (K + needs[i] - a + 1))) {
                a = needs[i];
                b = needs[i + 1];
                streak = false;
                ans += K * 2 + 2 + b - a;
            } else {
                b = needs[i];
            }
        }
    }
    cout << ans;
}