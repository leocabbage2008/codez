#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ifstream fin("shell.in");
  ofstream fout("shell.out");
  int N;
  fin >> N;
  int shells[N][2];
  int guesses[N][1];
  for (int i = 0; i < N; ++i) {
    fin >> shells[i][0] >> shells[i][1] >> guesses[i][0];
    shells[i][0]--, shells[i][1]--, guesses[i][0]--;
  }
  int sol = -1;
  for (int i = 0; i < 3; ++i) {
    int sim[3] = {0, 1, 2};
    int correct = 0;
    for (int j = 0; j < N; ++j) {
      swap(sim[shells[j][0]], sim[shells[j][1]]);
      if (sim[guesses[j][0]] == i) {
        correct++;
      }
    }
    sol = max(correct, sol);
  }
  fout << sol;
}