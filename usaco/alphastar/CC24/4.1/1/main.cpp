#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int yeard(string start, string end, string pon) {
    vector<string> cycle = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog",
                            "Pig", "Rat"};
    int i = 0;
    while (cycle[i] != start)
        i++;
    int counter = 0;
    cout << i << " " << counter << endl;
    if (pon == "previous") {
        counter = -1;
        i--;
        i += 12;
        i %= 12;
        while (cycle[i] != end) {
            counter--;
        }
    } else {
        counter = 1;
        while (cycle[i] != end) {
            i++;
            i += 12;
            i %= 12;
            counter++;
        }
    }
    return counter;
}

vector<string> get_info(string cow, vector<string> names, vector<int> years, vector<string> zodiacs) {
    for (int i = 0; i < names.size(); ++i) {
        if (names[i] == cow)
            return {to_string(years[i]), zodiacs[i]};
    }
    return {"invalid", "invalid"};
}

int main() {
    int N;
    cin >> N;
    vector<string> names;
    vector<int> years;
    vector<string> zodiacs;
    names.push_back("Bessie");
    years.push_back(0);
    zodiacs.push_back("Ox");
    for (int i = 0; i < N; ++i) {
        string cow1, s, pon, zodiac, cow2;
        cin >> cow1 >> s >> s >> pon >> zodiac >> s >> s >> cow2;
        names.push_back(cow1);
        zodiacs.push_back(zodiac);
        vector<string> info = get_info(cow2, names, years, zodiacs);
        int year = stoi(info[0]) + yeard(info[1], zodiac, pon);
        years.push_back(year);
        if (cow1 == "Elsie") {
            info = get_info("Elsie", names, years, zodiacs);
            year = stoi(info[0]);
            cout << abs(year);
            return 0;
        }
    }
}