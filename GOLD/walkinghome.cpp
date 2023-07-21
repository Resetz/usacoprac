#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            char c;
            cin >> c;
            grid[i][j] = c == 'H';
            //cout << grid[i][j] << endl;
        }
    }
    //cout << "here" << endl;
    vector<vector<vector<vector<int>>>> dp(k+2, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(2, 0))));
    dp[0][1][0][1] = dp[0][0][1][0] = 1;
    for (int i = 0 ; i <= k ; i++) {
        //cout << "- " << i << endl;
        for (int j = 0 ; j < n ; j++) {
            for (int l = 0 ; l < n ; l++) {
                if (grid[j][l]) continue;

                dp[i][j][l+1][0] += dp[i][j][l][0]; // go to the right
                dp[i+1][j+1][l][1] += dp[i][j][l][0]; // going right, now want to go down
                

                dp[i][j+1][l][1] += dp[i][j][l][1]; // go down
                dp[i+1][j][l+1][0] += dp[i][j][l][1]; // going down, now want to go right

         
            }
        }
    }

    int ans = 0;
    for (int i = 0 ; i <= k ; i++) {
        ans += dp[i][n-1][n-1][0] + dp[i][n-1][n-1][1];
        //cout << i << " " << dp[i][n-1][n-1][0] + dp[i][n-1][n-1][1] << endl;
    }
    cout << ans << endl;
}

int main() {
    int n = 1;
    cin >> n;
    while (n--) solve();
}