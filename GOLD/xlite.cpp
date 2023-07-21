#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

long long countz(long long k) {
    int ret = 0;
    while (k > 0) {
        if (k & 1) ret++;
        k /= 2;
    }
    return ret;
}

string tos(long long k) {
    string ret;
    while (k > 0) {
        ret += (k&1 ? "1" : "0");
        k /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string tos(long long k, int l) {
    string ret;
    for (int i = l-1 ; i >= 0 ; i--) {
        ret += (((k>>i) & 1) ? "1" : "0");
    }
    return ret;
}

int main() {
    int l, t;
    cin >> l >> t;
    vector<bool> v(l);
    long long vi = 0;
    long long pow = binpow(2, l-1);
    for (int i = 0; i < l ; i++) {
        char k;
        cin >> k;
        v[i] = k == '1';
        if (v[i]) {
            vi += pow;
        }
        pow /= 2;
    }
    vector<bool> m(t);
    pow = binpow(2,t-1);
    long long mi = 0;
    long long mask = 0;
    for (int i = 0; i < t ; i++) {
        char k;
        cin >> k;
        m[i] = k == '1';
        if (m[i]) {
            mi += pow;
        }
        mask += pow;
        pow /= 2;
    } 

    int tmask = mask;
    
    int n = l;
    long long k = binpow(2, t+1);
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(binpow(2, t+1), INT_MAX)));
    dp[0][0][vi >> (l-t)] = 0;
    //dp[0][1][(vi >> (l-t)) ^ mi] = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            for (int o = 0 ; o < k ; o++) {
                if (dp[i][j][o] == INT_MAX) {
                    continue;
                }

                //cout << i << " " << j << " " << tos(o) << " " << dp[i][j][o] << endl;
                long long pre = o;
                pre ^= mi;
                pre = (pre << 1) + (i+t < n && v[i+t]);

                if (i <= n-t) {
                    //if (!((i+1)%3)) cout << i+1 << " " << j+1 << " " << dp[i][j][o] + ((pre >> t) > 0) << endl;
                    dp[i+1][j+1][pre & mask] = min(dp[i+1][j+1][pre & mask], dp[i][j][o] + ((pre >> t) > 0));
                }

                pre = (o << 1) + (i+t < n && v[i+t]);
                dp[i+1][j][pre & mask] = min(dp[i+1][j][pre & mask], dp[i][j][o] + ((pre >> t) > 0));

                /*
                dp[i+1][j+1][pre & mask] = min(dp[i+1][j+1][pre & mask], dp[i][j][pre] + ((pre >> t) > 0));
                cout << i+1 << " " << j+1 << " " << (pre & mask) << endl;*/
            }
        }
    }

    //cout << "here" << endl;
    int ans = 0;
    int cur = INT_MAX;
    for (int i = 0 ; i <= n ; i++) {
        for (int o = 0 ; o < k ; o++) {
            if (dp[n][i][o] == INT_MAX) {
                continue;
            }
            //cout << i << " " << o << " " << dp[n][i][o] << endl;
            if (dp[n][i][o] < cur) {
                ans = i;
                cur = dp[n][i][o];
            } else if (dp[n][i][o] == cur) {
                ans = min(ans, i);
            }
        }
        
    }
    cout << ans << endl;//<< " " << cur << endl;

}