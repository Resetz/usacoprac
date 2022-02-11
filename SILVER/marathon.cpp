#include <iostream>
#include <vector>
#include <climits>

#define dist(a, b) abs(pos[a].first-pos[b].first) + abs(pos[a].second-pos[b].second)

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<pair<int,int>> pos(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    vector<int> cur(s+1);
    vector<int> pre(s+1);

    vector<vector<int>> dp(n, vector<int>(s+1, 100000000));
    dp[0][0] = 0;
    dp[1][0] = dist(0,1);
    for (int i = 0 ; i < s+1; i++) {
        dp[0][i] = 0;
        dp[1][i] = dist(0,1);
    }

    for (int i = 2 ; i < n ; i++) {
        for (int j = 0; j <= min(s, i-1); j++) {
            for (int k = 0 ; k <= j ; k++) {
                dp[i][j] = min(dp[i][j], dp[i-k-1][j-k] + dist(i-k-1,i));
            }
            //cout << dp[i][j] << " ";
        }
        for (int j = min(s, i-1)+1; j < s+1 ; j++) dp[i][j] = dp[i-1][j];
    }

    cout << dp[n-1][s] << endl;

}
