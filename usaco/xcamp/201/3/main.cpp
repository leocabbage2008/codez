#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n, k;

void perm(vector<int> a) {
    if (a.size() == n) {
        int sum = 0;
        for (int i: a) sum += i;
        if (sum % k == 0) {
            for (int i: a) cout << i << " ";
            cout << endl;
        }
        return;
    } else {
        for (int i = 1; i <= n; ++i) {
            vector<int> b = *&a;
            b.push_back(i);
            perm(b);
        }
    }
}

int main() {
    cin >> n >> k;
    vector<int> arr(0);
    perm(arr);
}