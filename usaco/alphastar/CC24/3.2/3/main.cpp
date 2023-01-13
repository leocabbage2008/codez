#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long long N;
    cin >> N;
    long long a[N], b[N];
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];
    sort(a, a + N);
    sort(b, b + N);
    long long s[N];
    long long j = N - 1;
    for (long long i = N - 1; i >= 0; --i) {
        while (j >= 0 and b[j] >= a[i]) {
            j--;
        }
        s[i] = N - j - 1;
    }
    long long ans = 1;
    for (long long i = N - 1; i >= 0; --i) {
        ans *= s[i] - (N - 1 - i);
    }
    cout << ans;
}