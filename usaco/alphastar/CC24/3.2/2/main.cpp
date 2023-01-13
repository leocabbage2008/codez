#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int id[N], e = 0, o = 0;
    for (int i = 0; i < N; ++i) cin >> id[i];
    for (int i = 0; i < N; ++i) {
        if (id[i] % 2) o++;
        else e++;
    }
    while (e < o) {
        o -= 2;
        e++;
    }
    if (e == o || e == o + 1)
        cout << e + o << endl;
    else cout << 2 * o + 1;
}