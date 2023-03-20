#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, total;
    cin >> N >> total;
    int mm[N][2];
    int sol[N][2];
    for (int i = 0; i < N; ++i) cin >> mm[i][0] >> mm[i][1];
    for (int i = 0; i < N; ++i) {
        total -= mm[i][0];
        sol[i][0] = mm[i][0];
    }
    if (total < 0) {
        cout << "NO";
        return 0;
    } else if (total == 0) {
        cout << "YES" << endl;
        cout << sol[0][0];
        for (int i = 1; i < N; ++i) cout << " " << sol[i][0];
        cout << endl;
        return 0;
    }
    int c = 0;
    while (true) {
        if (sol[c][0] == mm[c][1]) {
//            cout << "approaching " << c + 1 << " when " << sol[c][0] << " = " << mm[c][1] << endl;
            c++;
        }
        if (total == 0) {
            cout << "YES" << endl;
            cout << sol[0][0];
            for (int i = 1; i < N; ++i) cout << " " << sol[i][0];
            cout << endl;
            return 0;
        }
        if (c == N) {
            cout << "NO";
            return 0;
        }
//        cout << "at: " << sol[c][0] << " maxing out at " << mm[c][1] << " deciding to go to "
//             << min(total + sol[c][0], mm[c][1]) << " while subtracting "
//             << -(sol[c][0] - min(total + sol[c][0], mm[c][1])) << " with total of " << total << endl;
        int x = total - (min(total + sol[c][0], mm[c][1]) - sol[c][0]);
//        cout << sol[c][0] << " is sol[c][0]" << endl;
        sol[c][0] = min(total + sol[c][0], mm[c][1]);
//        cout << sol[c][0] << " is sol[c][0]" << endl;
//        cout << "total is before: " << total << endl;
        total = x;
//        cout << "total is now: " << total << endl;
//        cout << endl;
    }

}