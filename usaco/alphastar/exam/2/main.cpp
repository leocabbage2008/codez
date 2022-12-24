#include <iostream>
#include <algorithm>
#include <regex>
#include <string>

using namespace std;

int main() {
    int n;
    string x, a;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cin >> x;
    a = to_string(stoi(x)+1);
    for (int i = 0; i < n; ++i) {
        cout << regex_replace(arr[i],regex(x),a) << endl;
    }
}