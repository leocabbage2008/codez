#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        int curr_y = 0;
        int max_y = 0;
        string ans = "";
        for (int j = 0; j < s.size(); ++i) {
            if (s[j] == 'N') curr_y += 1;
            else if (s[j] == 'S') curr_y -= 1;
            max_y = max(max_y, curr_y);
            if (curr_y != max_y) continue;
            if (s[j] == 'E') ans = "ccw";
            else ans = "cw";
        }
        cout << ans;
    }
}