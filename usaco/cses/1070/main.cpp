#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n==1){
        cout << 1 << endl;
    }
    else if(n>3) {
        cout << 2;
        for (int i = 4; i <= n; i += 2) {
            cout << " " << i;
        }
        for (int i = 1; i <= n; i += 2) {
            cout << " " << i;
        }
        cout << endl;
    } else{
        cout << "NO SOLUTION" << endl;
    }
}