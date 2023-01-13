#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int find_h(int papers[], int N) {
    int h = 0;
    for (int i = N - 1; i >= 0; i++) {
        if (papers[i] >= h + 1)h++;
        else return h;
    }
    return h;
}

int main() {
    int N, L;
    cin >> N >> L;
    int papers[N];
    for (int i = 0; i < N; ++i) cin >> papers[i];

    sort(papers, papers + N);

    int h = find_h(papers, N);

    if (h == N) {
        cout << h;
        return 0;
    }

    if (papers[N - h - 1] < h) {
        cout << h;
        return 0;
    }

    int k = 0;
    for (int i = N - h; i >= N - 1; --i) {
        if (papers[i] == h) k++;
        else break;
    }
    if (L >= k + 1) cout << h + 1;
    else cout << h;
}