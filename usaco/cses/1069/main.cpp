#include <iostream>
using namespace std;

int main() {
    string DNA;
    int m = 1, c = 1;
    cin >> DNA;
    for (int i = 0; i < DNA.size() - 1; ++i) {
        if (DNA[i + 1] == DNA[i]) c++;
        else c = 1;
        if (c > m) m = c;
    }
    cout << m << endl;
}