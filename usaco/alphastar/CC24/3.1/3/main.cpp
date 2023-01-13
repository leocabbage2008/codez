#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

void make_event(int east, int north, char points[][3], vector<vector<int>> events) {
    if (points[north][1] < points[east][1]) return;
    if (points[east][2] < points[north][2]) return;
    int dist_east = points[north][1] - points[east][1];
    int dist_north = points[east][2] - points[north][2];
    if (dist_east == dist_north) return;
    if (dist_east < dist_north) {
        vector<int> t = {dist_east, dist_north, east, north};
        events.push_back(t);
    } else {
        vector<int> t = {dist_east, dist_north, north, east};
        events.push_back(t);
    }
}

bool sortByCol(const vector<int> &v1, const vector<int> &v2) { return v1[1] < v2[1]; }

int main() {
    int N;
    cin >> N;
    char points[N][3];
    for (int i = 0; i < N; ++i) cin >> points[i][0] >> points[i][1] >> points[i][2];

    vector<vector<int>> events;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (points[i][0] == 'E' && points[j][0] == 'N')
                make_event(i, j, points, events);
            else if (points[i][0] == 'N' && points[j][0] == 'E')
                make_event(j, i, points, events);
        }
    }
    sort(events.begin(), events.end(), sortByCol);

    int grass[N];
    bool stopped[N];
    for (int i = 0; i < N; ++i) {
        grass[i] = 0;
        stopped[i] = false;
    }
    for (int i = 0; i < events.size(); ++i) {
        if (stopped[events[i][3]])
            continue;
        if (!stopped[events[i][2]] || (grass[events[i][2]] >= events[i][0])) {
            stopped[events[i][3]] = true;
            grass[events[i][3]] = events[i][1] - 1;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (stopped[i]) cout << grass[i] << endl;
        else cout << "Infinity" << endl;
    }

}