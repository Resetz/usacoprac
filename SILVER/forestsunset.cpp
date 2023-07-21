#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>


using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,pair<int,int>>> v(n);
    vector<int> a;
    set<int> s;
    map<int,vector<int>> m;
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].second.first >> v[i].second.second >> v[i].first;

        int f, t;
        f = v[i].second.first;
        t = v[i].second.second;

        if (s.insert(f).second) {
            a.push_back(f);
        }
        m[f].push_back(v[i].first);

        if (s.insert(t).second) {
            a.push_back(t);
        }
        m[t].push_back(-v[i].first);
    }
    sort(a.begin(), a.end());
    multiset<int> cur;
    for (int i = 0 ; i < m[a[0]].size() ; i++) {
        //cout << m[a[0]][i] << " ";
        cur.insert(m[a[0]][i]);
    }
   // cout << endl;
    unsigned long long ans = 0;
    for (int i = 1 ; i < a.size() ; i++) {
        if (cur.size() > 0) {
            ans += (a[i]-a[i-1])*(*cur.rbegin());
        }
        for (int j = 0 ; j < m[a[i]].size() ; j++) {
            //cout << m[a[i]][j] << " ";
            if (m[a[i]][j] < 0) {
                cur.erase(-m[a[i]][j]);
            } else {
                cur.insert(m[a[i]][j]);
            }
        }
        //cout << endl;
    }
    cout << ans << endl;
}