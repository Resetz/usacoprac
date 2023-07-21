#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long long k,n;
    cin >> k >> n;
    vector<long long> coins(k);
    vector<long long> v(n);
    long long total = 0;
    for (long long i = 0 ; i < k ; i++) {
        cin >> coins[i];
        total += coins[i];
    }
    for (long long i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    vector<vector<long long>> num((long long)(k), vector<long long>(n+1));
    for (long long i = 0 ; i < k ; i++) {
        long long r = 0;
        long long sum = 0;
        long long ls = 0;
        for (long long j = 0 ; j <= n ; j++) {
            while (r != n && sum - ls + v[r] <= coins[i]) {
                //cout << coins[i] << " " << sum << " " << ls << endl;
                sum += v[r];
                r++;
            }
            //cout << i << " " << j << ": " << r << " " << sum << endl;
            num[i][j] = r;
            ls += v[j];
        }
    }
    //cout << "here" << endl;

    long long p = (long long)(pow(2,k));
    vector<long long> dp(p, -1);
    dp[0] = 0;
    for (long long i = 0 ; i < p ; i++) {
        if (dp[i] != -1) {
            //cout << i << " -> " << dp[i] << endl; 
            for (long long j = 0 ; j < k ; j++) {
                if (!(i & (1 << j))) {
                    dp[i+(1 << j)] = max(num[j][dp[i]], dp[i+(1 << j)]) ;
                }
            }
        }
    }
    long long ans = -1;
    for (long long i = 0 ; i < p ; i++) {
        long long cur = -1;
        if (dp[i] == n) {
            cur = 0;
            for (long long j = 0 ; j < k ; j++) {
                if (i & (1 << j)) cur += coins[j]; 
            }
        }
        if (cur != -1) {
            ans = max(ans, total - cur);
        }
    }
    cout << ans << endl;
}