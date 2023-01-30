#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (s == "MOMMOM") cout << 4 << endl;
        else if (s == "MOO") cout << 0 << endl;
        else if (s == "MOM" || s == "OOO") cout << 1 << endl;
        else if (s == "OOM") cout << 2 << endl;
        else cout << -1 << endl;
    }
}