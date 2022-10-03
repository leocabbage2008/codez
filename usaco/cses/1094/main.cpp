#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long c = 0;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            c += a[i] - a[i+1];
            a[i + 1] = a[i];
        }
    }
    cout << c;
}
