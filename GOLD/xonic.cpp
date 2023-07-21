#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) cin >> v[n-i-1];


    vector<vector<int>> dp(n+1, vector<int>(n+1));

    vector<int> pf(n+1, 0);
    for (int i = 0 ; i < n ; i++) {
        pf[i+1] = pf[i] + v[i];
    }

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            dp[i][j] = dp[i][j-1];
            if (i >= 2*j-1) {
                dp[i][j] = max(dp[i][j], pf[i] - dp[i-2*j+1][2*j-1]);
            }
            if (i >= 2*j) {
                dp[i][j] = max(dp[i][j], pf[i] - dp[i-2*j][2*j]);
            }
        }
    }
    cout << dp[n][1] << endl;
}