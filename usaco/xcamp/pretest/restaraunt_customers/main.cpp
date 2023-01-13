#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int times[n * 2];
    for (int i = 0; i < n * 2; ++i) cin >> times[i];
    int mx = 0, mn = times[0];
    for (int i = 0; i < n * 2; ++i) {
        if (times[i] > mx) mx = times[i];
        if (times[i] < mn) mn = times[i];
    }
    int a[mx - mn + 1];
    for(int i = 0; i < mx-mn+1; ++i) a[i]=0;
    for (int i = 0; i < n * 2; i += 2) {
        for (int j = times[i]; j <= times[i + 1]; ++j)
            a[j-1]++;

    }
    int m = 0;
    for(int i = 0; i < mx-mn+1; ++i){
        if(a[i]>m) m=a[i];
    }
    cout << m << endl;
    // too slow
}
