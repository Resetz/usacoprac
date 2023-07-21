#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n ; i++) cin >> a[i];
    for (int i = 0; i < n ; i++) cin >> b[i];


    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1; j <= n ; j++) {
            dp[i][j] = max(dp[i-1][j-1]+(abs(a[i]-b[j]) <= 4), max(dp[i-1][j], dp[i][j-1]));
        }
    }

    cout << dp[n][n];
}