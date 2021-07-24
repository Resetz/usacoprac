#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <set>

using namespace std;

unordered_map<int, int> freqX;
unordered_map<int, int> freqY;
set<int> found;
vector<pair<int,int>> points;
int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        int y;
        cin >> x >> y;
        pair<int,int> next(x , y);
        points.push_back(next);
    }

    for(int i = 0;i < n; i++) {
        pair<int, int> point = points[i];
        freqX[point.first]++;
        freqY[point.second]++;
    }
    if (freqX.size() <= 3) {
        cout <<  1 << endl;
    } else if (freqY.size() <= 3) {
        cout <<  1 << endl;
    }
    else {
        int best = 0;
        int most = 0;
        for( pair<int, int> a : freqX) {
            if (a.second > most) {
                most = a.second;
                best = a.first;
            }
        }
        for( pair<int, int> a : points) {
            if (a.first != best) {
                found.insert(a.second);
            }
        }
        if (found.size() <= 2) {
            cout << 1 << endl;
            return 0;
        }
        found.clear();
        best = 0;
        most = 0;
        for( pair<int, int> a : freqY) {
            if (a.second > most) {
                most = a.second;
                best = a.first;
            }
        }
        for( pair<int, int> a : points) {
            if (a.second != best) {
                found.insert(a.first);
            }
        }
        if (found.size() <= 2) {
            cout << 1 << endl;
            return 0;
        }
         cout << 0 << endl;
    }
   
}