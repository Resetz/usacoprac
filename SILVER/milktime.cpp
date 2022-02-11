#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m,r;
    cin >> m >> n >> r;

    vector<int> dp(n+1, 0);


    vector<pair<pair<int,int>,int>> v(n);


    for (int i = 0 ; i < n ; i ++) {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;
        v[i].first.second+=r;
    }

    sort(v.begin(),v.end());

    int ans =0 ;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j < i ; j++) {
            if (v[j].first.second > v[i-1].first.first) continue;
            else {
                dp[i] = max(dp[i], dp[j+1]);
            }
        }
        dp[i] += v[i-1].second;
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}