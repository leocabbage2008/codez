#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    int arr[8];
    ifstream fin("square.in");
    ofstream fout("square.out");
    for(int i = 0; i < 8; ++i) fin >> arr[i];
    int a = max(max(max(abs(arr[0]-arr[6]),abs(arr[0]-arr[2])),max(abs(arr[2]-arr[4]),abs(arr[4]-arr[6]))),max(max(abs(arr[1]-arr[7]),abs(arr[1]-arr[3])),max(abs(arr[3]-arr[5]),abs(arr[5]-arr[7]))));
    fout << a*a;

}