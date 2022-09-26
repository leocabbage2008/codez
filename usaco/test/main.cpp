#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("test.in");
    int a;
    fin >> a;
    cout << a;
    return 0;
}
