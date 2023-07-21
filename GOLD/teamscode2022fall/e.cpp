#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <climits>

using namespace std;

int main() {
    pair<int,int> streak;
    int n,k;
    cin >> n >> k;
    map<string, int> m;
    vector<int> v(n, 100);

    int mi = 0;
    pair<int,int> curstreak = {-1,-1};
    for (int i = 0 ; i < k ; i++) {
        string a;
        int c;
        cin >> a >> c;
        if (m.find(a) == m.end()) {
            m[a] = mi++;
        }
        v[m[a]] -= c;
        if (m[a] == curstreak.first) {
            curstreak.second++; 
        } else {
            if (streak.second < curstreak.second) streak = curstreak;
            curstreak = {m[a], 1};
        }
        //cout << curstreak.first << " " << curstreak.second << endl;
    }
    if (streak.second < curstreak.second) streak = curstreak;

    int high = -INT_MAX;
    int low = INT_MAX;
    for (int i = 0 ; i < n ; i++) {
        if (i == streak.first) {
            v[i] -= streak.second*(n-1);
        } else {
            v[i] += streak.second;
        }
        //cout << v[i] << endl;
       // cout << v[i] << endl;
        high = max(high, v[i]);
        low = min(low, v[i]);
    }
    cout << high-low << endl;
}