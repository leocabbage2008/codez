#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long arr[N];
    for (long long i = 0; i < N; ++i) cin >> arr[i];
    sort(arr,arr+N);
    vector<long long> store(N);
    long long m = 0;
    for (long long i = 0; i < N; ++i) {
        long long s = (N-i)*arr[i];
        store[i] = s;
        if (store[m] < s) m = i;
    }
    cout << store[m] << " " << arr[m];
}