#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> v(n);
    for (int i = 0 ; i < n ; i++) cin >> v[i].first >> v[i].second;

    vector<int> ans(k+1, INT_MAX);
    ans[0] = 0;
    for (int i = 0; i <= k ; i++) {
        if (ans[i] == INT_MAX) continue;
        for (int j = 0 ; j < v.size() ; j++) {
            if (i + v[j].first >= k) {
                ans[k] = min(ans[k], ans[i]+v[j].second);
                //cout << k << " " << ans[k] << endl;
            } else {
                ans[i+v[j].first] = min(ans[i+v[j].first], ans[i]+v[j].second);
                //cout << i+v[j].first << " " << ans[i+v[j].first] << endl;
            }
        }
    }
    cout << ans[k] << endl;
    
}