#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> v(n);
    vector<int> d(2*n);
    for (int i = 0 ; i < n ; i++) {
        int pos, r; cin >> pos >> r;
        v[i] = {pos-r, pos+r};
        d[i*2] = pos-r;
        d[i*2+1] = pos+r;
    }
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (int i = 0; i < n; ++i) {
        v[i].first = lower_bound(d.begin(), d.end(), v[i].first) - d.begin();
        v[i].second = lower_bound(d.begin(), d.end(), v[i].second) - d.begin();
    }

    sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
        if (a.first < b.first) return true;
        if (a.first == b.first) return a.second > b.second;
        return false;
    });

    vector<bool> plustwo(n, true);

    stack<pair<int,int>> endings;
    int cur = 0;
    for (int i = 0 ; i < d.size() ; i++) {
       // cout << "i = " << i << endl;
        while (endings.size() > 0 && endings.top().first <= i) {
            //cout << "- " << endings.top().first << " " << endings.top().second << endl;
            endings.pop();
        }
        while (cur < n && v[cur].first <= i) {
            //cout << "+ " << v[cur].first << " " << v[cur].second << endl;
            endings.push({v[cur].second, cur});
            cur++;
        }
        if (endings.size() > 0) {
            //cout << "m " << endings.top().second << endl; 
            plustwo[endings.top().second] = false;
        }
        //cout << endl;

    }

    int ans = n;
    for (int i = 0 ; i < n ; i++) {
        ans += plustwo[i];
    }
    cout << ans+1 << endl;
}