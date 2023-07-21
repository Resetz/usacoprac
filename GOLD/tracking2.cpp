#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long MOD = 1e9+7;
long long binpow(long long x, long long y) {
    if (y <= 0) return 1;
    else if (y % 2 == 1) return (x * binpow(x,y-1) + MOD) % MOD;
    else return (binpow((x*x + MOD) % MOD, y/2) + MOD) % MOD;
}

int main() {
    long long n,k;
    cin >> n >> k;
    
    vector<long> v(n+1, 0);
    for (int i = 0 ; i < n-k+1 ; i++) {
        cin >> v[i];
        v[i]--;
    }
    
    long long pre = -1;
    long long cur = v[0];
    long long len = 0;
    long long ans = 1;
    long long dbg = 0;

    for (int i = 0 ; i <= n ; i++) {
        if (cur == v[i]) {
            len++;
        } else {
            if (pre > cur) {
                len -= k-1;
            }
            if (i != n && v[i] < cur) {
                len += k-1;
            }
            len--;
            //cout << len << " " << v[i] << " " << cur << " " << i << " woops" << endl;
            cout << len+2 << endl;
            vector<long long> dp(len+2);
            dbg += len+2;
            dp[0] = 1ll;
            dp[1] = 1ll;
            for (int i = 2 ; i <= min(k, len+1) ; i++) {
                dp[i] = (binpow(1e9-cur, i-1) + MOD) % MOD;
            }

            for (int i = k ; i < len+1 ; i++) {
                //cout << "a: " << (((long long)(1e9-cur+1)*dp[i] + MOD) % MOD) << endl;
                //cout << "b: " << (binpow(1e9-cur, k)*dp[i-k+1] + MOD) % MOD << endl;
                dp[i+1] = (((long long)(1e9-cur+1)*dp[i] + MOD) % MOD);
                if (i > k-1) {
                    dp[i+1] = (dp[i+1] - ((binpow(1e9-cur, k-1)*dp[i-k+1] + MOD) % MOD)+MOD) % MOD;
                }
            }        
            ans = (ans * dp[len+1] + MOD) % MOD;
            //cout << ans << endl;

            len = 1;
            pre = cur;
            cur = v[i];
        }
    }
    //cout <<dbg << endl;
    cout << (ans+MOD)%MOD << endl;
}