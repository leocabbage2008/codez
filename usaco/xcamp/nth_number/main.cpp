#include <iostream>

using namespace std;

long long r(int n) {
    long long a = 0, b = 1, c = 1;
    if(n==1) return 0;
    for (long long i = 3; i < n; ++i) {
        long long d = a + 2 * b + c;
        a = b;
        b = c;
        c = d;
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    cout << r(n);
}