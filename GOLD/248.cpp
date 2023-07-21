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

    vector<vector<int>> dp(n, vector<int>(n-1, -1));
    for (int i = 0 ; i < n ; i++) {
        dp[i][i] = v[i];
    }
    for (int i = 1 ; i < n ; i++) {
        //size 
        for (int j = 0 ; j < n-i ; j++) {
                //cout << j << " " << j+1 << endl;
            for (int k = j+1 ; k <= j+i ; k++) {
                if (dp[j][k-1] != -1 && dp[k][j+i] != -1) {
                    if (dp[j][k-1] == dp[k][j+i]) {
                        dp[j][i+j] = max(dp[j][i+j], dp[j][k-1]+1); 
                    }
                }
            }
            //cout << j << " " << i+j << " = " << dp[j][i+j] << endl; 
        }
    }
    int ans =0 ;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ;j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}