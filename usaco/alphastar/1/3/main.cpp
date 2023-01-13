#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;


int main() {
    long N, M;
    cin >> N >> M;
    long ans = 0, coef = 1;
    while (N % 2 == 1 && M % 2 == 1) {
        ans += coef;
        coef *= 4;
        N = N / 2;
        M = M / 2 ;
    }
    cout << ans;
}