#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, k;
    
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        char c;
        cin >> c;
        if (c == 'H') v[i] = 0;
        else if (c == 'P') v[i] = 1;
        else v[i] = 2;
    }

    vector<vector<int>> dp(k+1, vector<int>(3));
    vector<vector<int>> cur(k+1, vector<int>(3));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for (int i = 1 ; i <= n ; i++) {
        //cout << " - " << v[i-1] << endl;
        for (int j = 0 ; j <= k ; j++) {
            for (int l = 0 ; l < 3 ; l++) {
                int add = 0;
                if ((v[i-1]+1)%3 == l) {
                    add = 1;
                }
                cur[j][l] = dp[j][l];
                if (j > 0) {
                    cur[j][l] = max(max(dp[j-1][(l+2)%3], dp[j-1][(l+1)%3]), cur[j][l]);
                }
                cur[j][l] += add;
                //cout << i << " " << j << " " << l << " " << dp[i][j][l] << endl;
            }
        }
        dp = cur;
    }
    cout << max(max(cur[k][0], cur[k][1]), cur[k][2]) << endl;
}