#include <iostream>

using namespace std;

long long r(int n) {
    if(n==1) return 2;
    return r(n-1)+n;
}

int main() {
    int n;
    cin >> n;
    cout << r(n);
}