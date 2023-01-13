#include <iostream>
using namespace std;
int r(int n){
    if(n==1) return 1;
    if(n==2) return 3;
    if(n%2){
        return (r(n-1)*2%12345)-1;
    } else return (r(n-1)*2%12345)+1;
}
int main(){
    int n;
    cin >> n;
    cout << r(n) % 12345;
}