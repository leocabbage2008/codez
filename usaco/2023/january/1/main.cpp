#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
string s;
int originalCountH = 0, originalCountG = 0;

bool works(int h, int g, int E[]) {
    bool gWorks = false, hWorks = false;
    int countG = 0, countH = 0;
    for (int j = h; j < E[h]; ++j) {
        if (s[j] == 'H') {
            countH++;
        }
    }
    for (int j = g; j < E[g]; ++j) {
        if (s[j] == 'G') {
            countG++;
        }
    }
    if (countG == originalCountG) gWorks = true;
    if (countH == originalCountH) hWorks = true;
    if (gWorks && hWorks) return true;
    if (!gWorks && !hWorks) return false;
    if (!hWorks && gWorks) {
        if (h <= g && g < E[h]) return true;
    }
    else {
        if (g <= h && h < E[g]) return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> s;
    int E[N];
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'G')
            originalCountG++;
        else originalCountH++;
    }
    for (int i = 0; i < N; ++i) cin >> E[i];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j && s[i]=='H' && s[j]=='G') {
                if (works(i, j, E))
                    count++;
            }
        }
    }
    cout << count << endl;
}
