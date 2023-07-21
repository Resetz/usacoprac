#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;cin >> n;

    vector<pair<int,int>> v(n);


    set<int> all;
    set<int> cur;
    map<int,int> m;
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
        m[v[i].second] = 0;
        all.insert(v[i].second);
    } 

    sort(v.begin(), v.end());


    int r,l;
    r = 0;
    l = 0;
    int best = INT_MAX;
    for (int i = 0 ; i < n ; i++, r++) {
        while (l < n && cur != all) {
            cur.insert(v[l].second);
            //cout << v[l].second << endl;
            m[v[l].second]++;
            l++;
            if (cur == all) break;
        }
        //cout << "good " << r << " " << l-1 << endl;
        if (l >= n-1 && cur != all) {
            break;
        }

        best = min(v[l-1].first-v[r].first, best);

        if (--m[v[r].second] == 0) {
            cur.erase(v[r].second);
        }
       // cout << m[v[r].second] << endl;
    }
    cout << best << endl;
}