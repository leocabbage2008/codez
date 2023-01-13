#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

void reverse(int a[], int A1, int A2) {
    while (A1 < A2) {
        int temp = a[A1];
        a[A1] = a[A2];
        a[A2] = temp;
        A1++;
        A2--;
    }
}

void simulate(int a[], int A1, int A2, int B1, int B2) {
    reverse(a, A1, A2);
    reverse(a, B1, B2);
}

bool compare(int a[], int b[], int s) {
    for (int i = 0; i < s; ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    int N, K, A1, A2, B1, B2, steps = 0;
    cin >> N >> K >> A1 >> A2 >> B1 >> B2;
    A1--;
    A2--;
    B1--;
    B2--;
    int a[N], original[N];
    for (int i = 0; i < N; ++i) {
        a[i] = i + 1;
        original[i] = i + 1;
    }
    while (true) {
        simulate(a, A1, A2, B1, B2);
        steps++;
        if (compare(original, a, N)) break;
    }
    for (int i = 0; i < K % steps; ++i) {
        simulate(a, A1, A2, B1, B2);
    }
    for (int i: a) cout << i << endl;
}