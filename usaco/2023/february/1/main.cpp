#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long N, T;
    cin >> N >> T;
    long long bales[N][2];
    for (long long i = 0; i < N; ++i) {
        long long a[2];
        cin >> a[0] >> a[1];
        bales[i][0] = a[0] - 1;
        bales[i][1] = a[1];
    }
    int bank = 0;
    bool eaten[T];
    for (int i = 0; i < N - 1; ++i) {
        bank += bales[i][1];
        for (int j = bales[i][0]; j < bales[i + 1][0]; ++j) {
            if (bank) {
                eaten[j] = true;
                bank--;
            }
        }
    }
    for (int j = bales[N - 1][0]; j < min(bales[N - 1][0] + bales[N - 1][1] + bank, T); ++j) {
        eaten[j] = true;
    }
    int ans = 0;
    for(int i : eaten){
        ans+=i;
    }
    cout << ans;
//    long long bank = 0;
//    vector<int> eat(T);
//    for (int i = 0; i < T; ++i) {
//        eat[i] = 0;
//    }
//    for (long long i = 0; i < N - 1; ++i) {
//        long long diff = bales[i + 1][0] - bales[i][0] + 1;
//        if (diff > bales[i][1] + bank) {
////            cout << "a ranging: " << bales[i][0] << " " << bales[i][0] + bales[i][1] + bank << endl;
//            for (long long j = 0; j < bales[i][1] + bank; ++j) {
//                eat[j + bales[i][0]] = 1;
//            }
//            bank = 0;
//        } else {
////            cout << "b ranging: " << bales[i][0] << " " << bales[i + 1][0] << endl;
//            for (long long j = bales[i][0]; j <= bales[i + 1][0]; ++j) {
//                eat[j] = 1;
//            }
//            bank += bales[i][1] - diff;
//        }
////        cout << "bank: " << bank << endl;
////        for (int j: eat) {
////            cout << j << " ";
////        }
////        cout << endl;
//    }
////    cout << "c ranging: " << bales[N - 1][0] << " " << min(bales[N - 1][0] + bales[N - 1][1] + bank, T) << endl;
////    cout << "bank: " << bank << endl;
//    for (long long i = bales[N - 1][0]; i < min(bales[N - 1][0] + bales[N - 1][1] + bank, T); ++i) {
//        eat[i] = 1;
//    }
//    int ans = 0;
//    for (int i = 0; i < T; ++i) {
////        cout << eat[i] << " ";
//        ans += eat[i];
//    }
////    cout << endl;
//    cout << ans << endl;
}
//2 5
//1 10
//3 10