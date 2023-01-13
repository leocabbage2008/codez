#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    long long N;
    cin >> N;
    long long p[N], t[N];
    for (long long i = 0; i < N; ++i) cin >> p[i];
    for (long long i = 0; i < N; ++i) cin >> t[i];

    long long d[N];
    for (long long i = 0; i < N; ++i) {
        d[i] = p[i] - t[i];
    }
    long long sum = 0;
    for (long long i = 0; i < N - 1; ++i) {
        sum += abs(d[i + 1] - d[i]);
    }
    sum += abs(d[0]) + abs(d[N - 1]);

    cout << sum / 2;
}