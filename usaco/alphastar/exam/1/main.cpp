#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n], f = 0;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < n; ++i){
        if(arr[i] < 0){
            if(f==1) cout << " ";
            cout << arr[i];
            if(f==0) f=1;
        }
    }
    for(int i = 0; i < n; ++i){
        if(arr[i] > 0){
            cout << " " << arr[i];
        }
    }
}
