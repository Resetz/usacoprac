#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> v(n);
    v.push_back({0, 0});
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    dp[0][0] = 0;
    for (int i = 0 ; i <= n ; i++) {
        for (int j = 0 ; j <= n ; j++) {
            if (dp[i][j] == -1) continue;
            for (int k = i+1 ; k <= n ; k++) {
                if (k <= j || v[k].first < v[i].second) continue;
                dp[k][j] = max(dp[i][j]+1, dp[k][j]);
            }
            for (int k = j+1 ; k <= n ; k++) {
                if (k <= i || v[k].first < v[j].second) continue;
                dp[i][k] = max(dp[i][j]+1, dp[i][k]);
            }
        }
    }

    int ans = 0;
    for (int i = 0 ; i <= n ; i++) {
        for (int j = 0 ; j <= n ; j++) {
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans << endl;
}