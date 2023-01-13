#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;
    long long counter = 0;
    for (int i = 0; i < N; ++i) {
        int j = i - 1;
        while (j >= 0 && s[j] != s[i]) {
            j--;
        }
        int k = i + 1;
        while (k < N && s[k] != s[i]) {
            k++;
        }
        int l = i - j - 1;
        int r = k - i - 1;
        counter += (long) l * r + max(l - 1, 0) + max(r - 1, 0);
    }
    cout << counter;
}