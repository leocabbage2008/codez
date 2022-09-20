#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, ans = 0;
    cin >> a >> b;
    cin >> c >> d;
    if (a > c){
        swap(a, c);
        swap(b, d);
    }
    int answer = (b-a) + (d-c);

    if(b > c){
        answer = max(b,d)-a;
    }

    cout << answer << endl;

}
