#include <bits/stdc++.h>
using namespace std;

void setIO(string file = "") {
	// speed up
	cin.tie(0)->sync_with_stdio(0);
	if ((int)(file.size())) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
}


int main() {
	setIO();
  int arr[7];
  for(int i = 0; i < 7; ++i){
    cin >> arr[i];
  }
  sort(arr, arr + 7);
  int a = arr[0];
  int b = arr[1];
  int c = arr[6] - a - b;

  cout << a << " " << b << " " << c;

	return 0;
}
