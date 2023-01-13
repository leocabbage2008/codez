#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;
    vector<int> sizes;
    int curr_size = 0;
    for (int i = 0; i < N; ++i) {
        if (s[i] == '1') {
            sizes.push_back(curr_size);
            curr_size = 0;
        } else curr_size++;
    }
    sizes.push_back(curr_size);

    int largest_size = 0;
    int sec_largest_size = 0;
    for (int i = 1; i < sizes.size() - 1; ++i) {
        if (sizes[i] >= largest_size) {
            sec_largest_size = largest_size;
            largest_size = sizes[i];
        } else if (sizes[i] > sec_largest_size) {
            sec_largest_size = sizes[i];
        }
    }
    int orig_D = numeric_limits<int>::max();

    int ans = 0;
    if (sec_largest_size > 0)
        ans = max(ans, min(min(orig_D, (largest_size - 1) / 2 + 1), (sec_largest_size - 1) / 2 + 1));
    if (largest_size > 0)
        ans = max(ans, min(orig_D, (largest_size - 2) / 3 + 1));
    if (sizes[0] > 0 and sizes[sizes.size() - 1] > 0)
        ans = max(ans, min(min(orig_D, sizes[0]), sizes[sizes.size() - 1]));
    if (sizes[0] > 1)
        ans = max(ans, min(orig_D, ((sizes[sizes.size() - 1]) - 2) / 2 + 1));
    if (sizes[sizes.size() - 1] > 1)
        ans = max(ans, min(orig_D, (sizes[sizes.size() - 1] - 2) / 2 + 1));
    if (sizes[0] > 1 && largest_size > 0)
        ans = max(ans, min(min(orig_D, sizes[0]), (largest_size - 1) / 2 + 1));
    if (sizes[sizes.size() - 1] > 1 && largest_size > 0)
        ans = max(ans, min(min(orig_D, sizes[sizes.size() - 1]), (largest_size - 1) / 2 + 1));

    cout << ans;
}