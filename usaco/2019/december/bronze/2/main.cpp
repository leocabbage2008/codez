#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");
    int n;
    string s;
    fin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        string cache[n - i + 1];
        for (int j = 0; j <= n - i; ++j) {
            cache[j] = s.substr(j, i);
        }
        sort(cache, cache + n - i + 1);
        if(adjacent_find(cache,cache+n-i+1)==cache+n-i+1){
            fout << i << endl;
            break;
        }
    }
}