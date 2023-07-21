#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

int main() {

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n;
    cin >> n;

    vector<int> cows(3, 0);
    vector<pair<int,pair<int,int>>> v(n);

    for (int i = 0 ; i < n ; i++) {
        int a, b, c;
        string s;
        cin >> a >> s >> c;
        if (s == "Bessie") {
            b = 0;
        } else if (s == "Elsie") {
            b = 1;
        } else {
            b = 2;
        }
        v[i] = {a, {b, c}};
    }

    sort(v.begin(), v.end());

    set<int> prev;
    prev.insert(0);
    prev.insert(1);
    prev.insert(2);

    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        cows[v[i].second.first] += v[i].second.second;
       //cout << v[i].second.first << " " << v[i].second.second << endl;

        int curmax = -INT_MAX;
        set<int> cur;
        for (int j = 0 ; j < 3 ; j++) {
            if (cows[j] > curmax) {
                cur.clear();
                cur.insert(j);
            } else if (cows[j] == curmax) {
                cur.insert(j);
            }
            curmax = max(curmax, cows[j]);
        }
        if (prev != cur) ans++;
        //cout << endl;
        prev = cur;
    }
    cout << ans << endl;
}