#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    double n, i, s;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        s += 1 / i;
    }
    printf("%f",s);
}
