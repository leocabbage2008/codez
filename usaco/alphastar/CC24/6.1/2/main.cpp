#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int pos_a[N], pos_b[N];
    for (int i = 0; i < N; ++i) {
        int a_i;
        cin >> a_i;
        a_i--;
        pos_a[a_i] = i;
    }
    for (int i = 0; i < N; ++i) {
        int b_i;
        cin >> b_i;
        b_i--;
        pos_b[b_i] = i;
    }
    int pos[N];
    for (int i = 0; i < N; ++i) {
        pos[pos_a[i]] = pos_b[i];
    }
    int counter = 0;
    int prev_max = 0;
    for (int i = 0; i < N; ++i) {
        if (pos[i] < prev_max) counter++;
        else prev_max = pos[i];
    }
    cout << counter;

}