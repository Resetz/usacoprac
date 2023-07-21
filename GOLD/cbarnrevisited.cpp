#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    long long n, K;
    cin >> n >> K;

    vector<long long> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    long long ans = LLONG_MAX;
    for (int i = 0 ; i < n-1 ; i++) {
        vector<vector<long long>> dp(n+1, vector<long long>(K+1, -1));
        dp[0][0] = 0;
        for (int j = 0 ; j < n ; j++) {
            for (int k = 0 ; k < K ; k++) {
                if (dp[j][k] == -1) continue;
                long long sum = 0;
                for (int l = j ; l < n ; l++) {
                    sum += v[l] * (l - j);
                    if (dp[l+1][k+1] == -1) {
                        dp[l+1][k+1] = sum + dp[j][k];
                    } else {
                        dp[l+1][k+1] = min(dp[l+1][k+1], sum + dp[j][k]);
                    }
                }
            }
        }
        ans = min(ans, dp[n][K]);

        rotate(v.begin(), v.begin()+1, v.end());
    }

    cout << ans << endl;
}