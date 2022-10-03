#include <iostream>
using namespace std;

int t, h, w, steps, to = 0;

int main() {
    cin >> t;
    for(int _ = 0; _ < t; ++_){
        cin >> h >> w;
        steps = h + w - 1;
        int arr[h][w];
        for(int x = 0; x < h; ++x){
            for(int y = 0; y < w; ++y){
                cin >> arr[x][y];
            }
        }

    }
}
