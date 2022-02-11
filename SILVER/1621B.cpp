#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int,int>, int>> v(n);

    for (int i = 0; i < n ; i++) {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    }

    int minl = v[0].first.first;
    int maxr = v[0].first.second;
    int indl = 0;
    int indr = 0;
    int costl = v[0].second;
    int costr = v[0].second;
    int indlong = 0;

    for (int i = 0 ; i < n ; i++) {
        if (v[i].first.first < minl) {
            minl = v[i].first.first;
            costl = v[i].second;
            indl = i;
        } else if (v[i].first.first == minl) {
            if (v[i].second < costl) {
                costl = v[i].second;
                indl = i;
            }
        }

        if (v[i].first.second > maxr) {
            maxr = v[i].first.second;
            costr = v[i].second;
            indr = i;
        } else if (v[i].first.second == maxr) {
             if (v[i].second < costr) {
                costr = v[i].second;
                indr = i;
            }
        }
        if (v[indlong].first.second - v[indlong].first.first < v[i].first.second - v[i].first.first) {
            indlong = i;
        } else if (v[indlong].first.second - v[indlong].first.first == v[i].first.second - v[i].first.first && v[indlong].second > v[i].second) {
            indlong = i;
        }
        if (v[indlong].first.second == maxr && v[indlong].first.first == minl && 
            v[indr].second + v[indl].second > v[indlong].second) {
            cout << v[indlong].second << endl;
        } else if (indr == indl) {
            cout << v[indl].second << endl;
        } else {
            cout << v[indr].second + v[indl].second << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}