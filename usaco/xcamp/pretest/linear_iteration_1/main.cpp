#include <iostream>
#include <cmath>

using namespace std;

long long r(int n) {
    long long a = 1, b = 1;
    for(long long i = 1; i < n; ++i){
        long long c = a+b;
        b=a;
        a=c;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    cout << r(n) % 1000000007;
}
