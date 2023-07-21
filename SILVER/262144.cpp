#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }
    vector<vector<int>> dp(n, vector<int>(60,-1));
    for (int i = n-1 ; i >= 0 ; i--) {
        dp[i][v[i]] = i;
        for (int j = 1 ; j < 60 ; j++) {
            if (dp[i][j-1] != -1 && dp[i][j-1] != n-1) {
                dp[i][j] = dp[dp[i][j-1]+1][j-1];
            }
        }
    }
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 1 ; j < 60 ; j++) {
            if (dp[i][j] != -1) ans = max(j, ans);
        }
    }
    cout << ans << endl;
}