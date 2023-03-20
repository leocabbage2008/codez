#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#pragma GCC optimize ("O2")

using namespace std;

int N, m = 20000;
vector<vector<int>> mat;
vector<int> stack;

void job(int i, int sum) {
    if (i == N) {
        m = min(m, sum);
        return;
    }
    for (int j = 0; j < N; ++j) {
        sum+=mat[i][j];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    int used[N];
    for (int i = 0; i < N; ++i) {
        vector<int> b(N);
        for (int j = 0; j < N; ++j) {
            cin >> b[j];
        }
        mat.push_back(b);
    }
    job(0, used,0);
    cout << m;
}

//int N;
//
//int main() {
//    cin >> N;
//    if (N == 1) {
//        cout << 4;
//        return 0;
//    }
//    int counter = 0;
//    for (int a = 0; a < N; ++a) {
//        for (int b = 0; b < N; ++b) {
//            if (a * a + b * b > N) continue;
//            for (int c = 0; c < N; ++c) {
//                double sol = sqrt(N - a * a - b * b - c * c);
//                if ((sol - ((int) sol) == 0.0)) {
//                    counter++;
////                    cout << a << " " << b << " " << c << " " << sol << endl;
//                }
//            }
//        }
//    }
//    cout << counter;
//}
//int N, B, m = 1000;
//
//int main() {
//    cin >> N >> B;
//    if(N%2==0) cout << 1;
//    else cout << 69;
//}