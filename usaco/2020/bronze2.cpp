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
	int c = 0;
	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = i; j <= N; ++j) {
			double avg = 0;
			for (int k = i; k < j; ++k) {
				avg += arr[k];
			}
			avg /= (j - i) | 1;
			for (int l = i; l < j; ++l) {
				if (avg == arr[l]) {
					++c;
				}
			}
		}
	}
	cout << c << endl;
	return 0;
}