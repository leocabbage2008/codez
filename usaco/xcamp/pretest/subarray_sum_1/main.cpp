#include <iostream>

using namespace std;

int main() {
    int n, x, s = 0;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i) {
        if (arr[i] == x)s++;
    }
    for (int j = 2; j < n; ++j) {
        LOOP:
        for (int i = 0; i < n - j; ++i) {
            int sum = 0;
            for (int a = i; a < i + j; ++a) {
                if (arr[a] > x)
                    goto LOOP;
                sum += arr[a];
            }
            if (sum == x) s++;
        }
    }
    cout << s << endl;
}