#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void pour(int a[], int b[]) {
  if (a[0] + b[0] <= b[1]) {
    b[0] += a[0];
    a[0] = 0;
  } else {
    a[0] -= b[1] - b[0];
    b[0] = b[1];
  }
}

// bool rep(int a[], int b[]) {
//   if (a[0] + b[0] <= b[1]) {
//     return false;
//   } else {
//     return true;
//   }
// }

// void slide(int window[4][3], int arr[3][2]) {
//   int values[3] = {arr[0][0], arr[1][0], arr[2][0]};
//   copy(begin(window[1]), end(window[1]), window[0]);
//   copy(begin(window[2]), end(window[2]), window[1]);
//   copy(begin(window[3]), end(window[3]), window[2]);
//   copy(begin(window[3]), end(window[3]), begin(values));
//   for (int i = 0; i < 4; ++i) {
//     cout << window[i][0] << " " << window[i][1] << " " << window[i][2] << "
//     x"
//          << endl;
//   }
//   cout << "----" << endl;
// }

int main() {
  ifstream fin("mixmilk.in");
  ofstream fout("mixmilk.out");
  int arr[3][2], pos = 0;
  for (int i = 0; i < 3; ++i) {
    fin >> arr[i][1] >> arr[i][0];
  }
  for (int i = 0; i < 100; ++i) {
    if (pos == 2)
      pour(arr[2], arr[0]);
    else
      pour(arr[pos], arr[pos + 1]);
    pos = (pos + 1) % 3;
  }
  for (int i = 0; i < 3; ++i) {
    fout << arr[i][0] << endl;
  }
  // int window[4][3] = {0};
  // while (true) {
  //   if (pos == 2)
  //     pour(arr[2], arr[0]);
  //   else
  //     pour(arr[pos], arr[pos + 1]);
  //   if (equal(begin(window[0]), end(window[0]), begin(window[3]))) {
  //     break;
  //   } else
  //     slide(window, arr);
  //   pos = (pos + 1) % 3;
  //   counter++;
  // }
  // cout << "-----" << endl;
  // cout << pos << " " << counter << endl;
  // cout << "------" << endl;
  // for (int i = 0; i < 3; ++i) {
  //   cout << arr[i][0] << " " << arr[i][1] << endl;
  // }
  // cout << "---------" << endl;
  // for (int i = 0; i < 4; ++i) {
  //   cout << window[i][0] << " " << window[i][1] << " " << window[i][2] <<
  //   endl;
  // }
}
// 31 10
// 11 2
// 50 40