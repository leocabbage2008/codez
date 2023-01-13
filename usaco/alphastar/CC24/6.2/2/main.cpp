#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    char dir[N];
    int p[N];
    for (int i = 0; i < N; ++i) cin >> dir[i] >> p[i];
    int ans = N - 1;
    for (int i = 0; i < N; ++i) {
        int liars = 0;
        for (int j = 0; j < N; ++j) {
            if (dir[j] == 'G' && p[i] < p[j])
                liars++;
            else if (dir[j] == 'L' && p[i] > p[j]) liars++;
        }
        ans = min(ans, liars);
    }
    cout << ans;
//    char c[N][2];
//    for (int i = 0; i < N; ++i) cin >> c[i][0] >> c[i][1];
//    int m = 1000;
//    for (int i = 0; i < N; ++i) {
//        int hl = c[i][1] - '0', liars = 0;
//        for (int j = 0; j < N; ++j) {
//            if (c[j][0] == 'G' && hl < c[j][1] - '0') {
//                liars++;
//            } else if (c[j][0] == 'L' && hl > c[j][1] - '0') {
//                liars++;
//            }
//        }
////        cout << c[i][0] << hl << " " << liars << endl;
//        m = min(m, liars);
//    }
//    cout << m;
}