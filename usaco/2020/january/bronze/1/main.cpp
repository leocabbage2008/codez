#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream fin("word.in");
    int n = 0, limit, word_count = 0;
    fin >> n >> limit;
    string words[n];
    for (int i = 0; i < n; ++i)
        fin >> words[i];
    int i = 0;
    ofstream fout("word.out");
    while (true) {
        int nowSize = words[i].size();
        if ((word_count + nowSize) <= limit) {
            if (word_count != 0)
                fout << " ";
            word_count += nowSize;
            fout << words[i];
            i++;
        } else {
            fout << endl;
            word_count = 0;
        }
        if ((i + 1) > n)
            break;
    }

    return 0;
}
