#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int numbers[7];
    for (int i = 0; i < 7; ++i) cin >> numbers[i];
    sort(numbers, numbers + 7);
    int A = numbers[0], B = numbers[1];
    cout << A << " " << B << " " << numbers[6] - A - B;
}