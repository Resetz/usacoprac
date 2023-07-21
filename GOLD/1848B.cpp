#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> v(n); for (int i=0; i<n; i++) {
        cin >> v[i];
        v[i]--;
    }
    vector<pair<int,int>> ans(m, {INT_MIN, INT_MIN});
    vector<int> last(m,-1);
    for (int i = 0 ; i < n ; i++) {
        int cur = max(0,(i) - last[v[i]]-1);
        //cout << i << " " << v[i] << " " << cur << " " << last[v[i]] << endl;

        if (cur <= ans[v[i]].first) {
            if (cur > ans[v[i]].second) {
                ans[v[i]].second = cur;
            }
        } else if (cur > ans[v[i]].first) {
            ans[v[i]].second = ans[v[i]].first;
            ans[v[i]].first = cur;
        }
        last[v[i]] = i;
    }

    for (int i = 0 ; i < m ; i++) {
        int cur = max(0, (n) - last[i]-1);
        //cout << cur << " " << i << endl;
        if (cur <= ans[i].first) {
            if (cur > ans[i].second) {
                ans[i].second = cur;
            }
        } else if (cur > ans[i].first) {
            ans[i].second = ans[i].first;
            ans[i].first = cur;
        }
    }
    int ret = INT_MAX;
    for (int i = 0 ; i < m ; i++) {
        //cout << ans[i].first << ", " << ans[i].second << endl;
        ret = min(ret, max(ans[i].second, ans[i].first/2));
    }
    cout << ret << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}