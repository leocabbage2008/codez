#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, K, currentLength = 0;
    string current;
    cin >> N >> K;
    while (N--) {
        string word;
        cin >> word;
        if (currentLength + word.length() > K) {
            if (current[0] == ' ' && current[current.length() - 1] != ' ') {
                cout << current.substr(1, current.length() - 1) << endl;
            } else if (current[0] != ' ' && current[current.length() - 1] == ' ') {
                cout << current.substr(0, current.length() - 1) << endl;
            } else if (current[0] == ' ' && current[current.length() - 1] == ' ') {
                cout << current.substr(1, current.length() - 2) << endl;
            } else {
                cout << current << endl;
            }
            current = "";
            current += word + " ";
            currentLength = word.length();
        } else {
            current += word + " ";
            currentLength += word.length();
        }
    }
    if(current!="") cout << current;
}