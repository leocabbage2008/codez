#include <iostream>
#include <cmath>

using namespace std;

double dist(int a[2], int b[2]){
    return sqrt(pow((b[0]-a[0]),2)+pow((b[1]-a[1]),2));
}

int main() {
    int N;
    cin >> N;
    int arr[N][2];
    for (int i = 0; i < N; ++i) cin >> arr[i][0] >> arr[i][1];
    int x = 0, y = 0;
    double m = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
//            cout << i << " " << j << ": " << abs(arr[i][0] - arr[j][0]) << " " << abs(arr[i][1] - arr[j][1]) << endl;
            if (dist(arr[i], arr[j])>m) {
                m=dist(arr[i],arr[j]);
                x = i;
                y = j;
            }
        }
    }
    cout << x + 1 << " " << y + 1;
}
