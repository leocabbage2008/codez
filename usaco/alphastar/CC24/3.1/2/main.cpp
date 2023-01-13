#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N, ans = 0;
    cin >> N;
    ans = N;
    float petals[N];
    for (int i = 0; i < N; ++i) cin >> petals[i];
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < N - i; ++j) {
            float sum = 0;
            for (int k = j; k <= j + i; ++k) sum += petals[k];
            sum /= (i + 1);
            for (int k = j; k <= j + i; ++k) {
                if (sum == petals[k]) {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
}