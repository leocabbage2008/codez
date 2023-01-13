#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;

int name_to_num(string name) {
    if (name == "Beatrice") return 0;
    else if (name == "Belinda") return 1;
    else if (name == "Bella") return 2;
    else if (name == "Bessie") return 3;
    else if (name == "Betsy") return 4;
    else if (name == "Blue") return 5;
    else if (name == "Buttercup") return 6;
    else if (name == "Sue") return 7;
    return -1;
}

int count_neighbors(int num, int arr[][2]) {
    int c = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[i][0] == num || arr[i][1] == num) c++;
    }
    return c;
}

string num_to_name(int num) {
    if (num == 0) return "Beatrice";
    else if (num == 1) return "Belinda";
    else if (num == 2) return "Bella";
    else if (num == 3) return "Bessie";
    else if (num == 4) return "Betsy";
    else if (num == 5) return "Blue";
    else if (num == 6) return "Buttercup";
    else if (num == 7) return "Sue";
    return "invalid";
}

int main() {
    cin >> N;
    int arr[N][2];
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        arr[i][0] = name_to_num(s);
        for (int j = 0; j < 4; ++j) cin >> s;
        cin >> s;
        arr[i][1] = name_to_num(s);
    }
    int sol[8];
    for (int i = 0; i < 8; ++i) sol[i] = -1;
    bool used[8] = {false};
    for (int cow = 0; cow < 8; ++cow) {
        if (count_neighbors(cow, arr) < 2) {
            sol[0] = cow;
            used[cow] = true;
            break;
        }
    }
    for (int i = 1; i < 8; ++i) {
        bool state = true;
        for (int j = 0; j < N; ++j) {
            if (sol[i - 1] == arr[j][0] && !used[arr[j][1]]) {
                sol[i] = arr[j][1];
                used[arr[j][1]] = true;
                state = false;
            } else if (sol[i - 1] == arr[j][1] && !used[arr[j][0]]) {
                sol[i] = arr[j][0];
                used[arr[j][0]] = true;
                state = false;
            }
        }
        if (state) {
            for (int cow = 0; cow < 8; ++cow) {
                if (used[cow]) continue;
                if (count_neighbors(cow, arr) < 2) {
                    sol[i] = cow;
                    used[cow] = true;
                    break;
                }
            }
        }
    }
    for (int i: sol) cout << num_to_name(i) << endl;
}