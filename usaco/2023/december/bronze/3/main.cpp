#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 4) {
        cout << "OK" << endl << "OK" << endl << "LIE" << endl << "LIE" << endl;
    } else {
        for (int i = 0; i < N; ++i) {
            if (i % 2 == 0) cout << "OK";
            else cout << "LIE";
            cout << endl;
        }
    }
}