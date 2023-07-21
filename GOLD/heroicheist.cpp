#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);


    v.push_back({-INT_MAX, 0});
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }
    v.push_back({INT_MAX, 0});
    sort(v.begin(), v.end());

    vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
    for (int i = 0; i < n; i++) {
        dp[i+1][i+1] = v[i+1].second;
    }

    for (int i = n ; i >= 1 ; i--) {
        for (int j = 1 ; j <= n; j++) {
            if (dp[i][j] == -1) continue;
            //eat to the right;
            if (j != n) {
                int left = min(i, (int)(lower_bound(v.begin(), v.end(), pair<int,int>{v[j].first-(v[j+1].first-v[j].first), 0}) - v.begin() - 1));
                if (left != -1) {
                    dp[left][j+1] = max(dp[left][j+1], dp[i][j] + v[j+1].second);
                }
                cout << i << " " << j << " -> " << left << " " << j+1 << " " << dp[i][j] + v[j+1].second << " | " << v[j].first-(v[j+1].first-v[j].first) << endl;
            }

            if (i != 1) {
                int right = max(j, (int)(upper_bound(v.begin(), v.end(), pair<int,int>{v[i].first+(v[i].first-v[i-1].first), 0}) - v.begin()));
                dp[i-1][right] = max(dp[i-1][right], dp[i][j] + v[i-1].second);
                cout << i << " " << j << " -> " << i-1 << " " << right << " " << dp[i][j] + v[i-1].second << endl;
            }
        }
    } 
    int ans = 0;
    for (int i = 0 ; i <= n+1 ; i++) {
        for (int j = 0 ; j <= n+1 ; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}