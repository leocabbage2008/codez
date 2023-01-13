#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool check(int a[], int N, int sum) {
    int i = 0;
    while (true) {
        int curr_sum = a[i];
        i++;
        while (i < N && curr_sum < sum) {
            curr_sum += a[i];
            i++;
        }
        if (curr_sum > sum) return false;
        if (i == N) return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int a[N], sum = 0;
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        for (int i = N; i >= 1; --i) {
            if (sum % i != 0) continue;
            if (check(a, N, sum / i)) {
                cout << N - i << endl;
                break;
            }
        }
    }
}