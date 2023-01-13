#include <cmath>
#include <iostream>

using namespace std;

string base2(string start, int n) {
    string result = start;
    for (int i = (int) (log2(n)); i >= 0; --i) {
        if (n >= pow(2, i)) {
            n -= pow(2, i);
            result += "1";
        } else result += "0";
    }
    return result;
}

int findLastBinary(string s) {
    string b = "";
    for (int i = 0; i < s.size(); ++i) {
        b += base2("0", (int) s[i]);
    }
    for (int i = 0; i < s.size(); ++i) {
        string f = base2("", i);
        if (b.find(f) == string::npos) {
            return i;
        } else {
            b.erase(b.find(f), f.size());
            if (b.find(f) != string::npos) {
                b.erase(b.find(f), f.size());
            }
            cout << b << endl;
        }
    }
    return s.size() - 1;
}

int main() {
    cout << findLastBinary("Roses are red.");

    return 0;
}