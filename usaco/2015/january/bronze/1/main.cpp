#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int a, b, c, d;
    ifstream fin("paint.in");
    ofstream fout("paint.out");
    fin >> a >> b >> c >> d;
    if (a > c){
        swap(a, c);
        swap(b, d);
    }
    int answer = (b-a) + (d-c);

    if(b > c){
        answer = max(b,d)-a;
    }

    fout << answer << endl;

}
