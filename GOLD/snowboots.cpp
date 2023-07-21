#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<pair<int,pair<int,int>>> v(n);
    vector<int> sortedv(n);

    for (int i = 0 ; i < n ; i++) {
        int num;
        cin >> num;
        v[i] = {num, {i-1, i+1}};
        sortedv[i] = i;
    }
    sort(sortedv.rbegin(), sortedv.rend(), [&v](int a,int b) { return v[a].first < v[b].first; });

    vector<pair<int,int>> b(m);
    vector<int> sortedb(m);
    for (int i = 0 ; i < m ; i++) {
        cin >> b[i].first >> b[i].second;
        sortedb[i] = i;
    }
    sort(sortedb.rbegin(), sortedb.rend(), [&b](int a,int c) { return b[a].first < b[c].first; });

    int curhigh = 0;
    int step = 1;
    vector<int> ans(m);
    for (int i = 0 ; i < m ; i++) {
        pair<int,int> boot = b[sortedb[i]];
        //cout << boot.first << " " << v[sortedv[curhigh]].first << endl;
        while (curhigh < n && boot.first < v[sortedv[curhigh]].first) {
            //pop;
            int cur = sortedv[curhigh];
            if (v[cur].second.first != -1) v[v[cur].second.first].second.second = v[cur].second.second;
            if (v[cur].second.second != n) v[v[cur].second.second].second.first = v[cur].second.first;
            step = max(step, v[cur].second.second - v[cur].second.first);
            //cout << "removed " << v[cur].first << " | dist is now " << v[cur].second.second - v[cur].second.first << endl;  
            curhigh++;
        }
        ans[sortedb[i]] = (boot.second >= step);
        
    }
    for (int i = 0 ; i < m ; i++) cout << ans[i] << endl;
}
