#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N][2];
    for (int i = 0; i < N; ++i) cin >> arr[i][0] >> arr[i][1];
    int R = abs(arr[1][0] - arr[0][0]);
    for (int i = 0; i < N - 1; ++i) {
        if (arr[i][1] != arr[i + 1][1])
            R = min(R, (int) abs(arr[i] - arr[i + 1]));
    }

}