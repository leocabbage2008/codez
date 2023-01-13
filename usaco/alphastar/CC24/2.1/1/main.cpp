#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int m = 0;
    cin >> N;
    float points[N][2];
    for (int i = 0; i < N; ++i) cin >> points[i][0] >> points[i][1];
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            if (a == b) continue;
            for (int c = 0; c < N; ++c) {
                if (c == a || c == b) continue;
                if (points[a][0] == points[b][0] && points[b][1] == points[c][1]) {
                    m = max(m, ((int) abs(points[b][1] - points[a][1]) * (int) abs(points[c][0] - points[a][0])));
                }
            }
        }
    }
    cout << m;
}