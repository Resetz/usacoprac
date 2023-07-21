#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
    
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }
    dp[0][0] = 0;


    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= m ; j++) {
            for (int k = 0 ; k < m; k++) {
                int val = (k-v[i-1]);
                if (j - (k)*(k) < 0) break;
                if (dp[i-1][j-k*k] == INT_MAX) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][j-k*k] + val*val);
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    if (dp[n][m] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[n][m] << endl;
    }
}