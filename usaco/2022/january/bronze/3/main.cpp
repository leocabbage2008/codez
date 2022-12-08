#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int r = 0; r < N; ++r) {
        int n, arr[100000];
        bool state = true;
        cin >> n;
        for (int t = 0; t < n; ++t) cin >> arr[t];
        while (state) {
            int a = arr[0];
            for (int i = 0; i < n - 1; ++i) {
                if (arr[i] < arr[i + 1])
                    arr[i + 1] -= arr[i];
            }
            for (int i = 0; i < n; ++i) {
                if (i < 0) {
                    cout << -1;
                    state = false;
                }
                if (a != arr[n]) {
                    cout << "yes";
                    state = false;
                }
            }
        }

    }
}
