using namespace std;
#include <iostream>
#include <algorithm>

int main() {
//    freopen("paint.in", "r", stdin);
//    freopen("paint.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    int x[b - a + d - c + 2];
    int e = 0;
    int f = 0;
    for (int i = 0; i < b - a + 1; ++i) {
        cout << a + i << endl;
        x[e] = a + i;
        ++e;
    }
    for (int i = 0; i < d - c + 1; ++i) {
        cout << c + i << endl;
        x[e] = c + i;
        ++e;
    }
    sort(x, x + b - a + d - c + 2);
    for (int i = 0; i < b - a + d - c + 2; ++i) {
        if (x[i] == x[i + 1]) f++;
    }
    sort(x, x + b - a + d - c + 2);
    for (int i = 0; i < b - a + d - c + 2; ++i) {
        cout << x[i] << endl;
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}
