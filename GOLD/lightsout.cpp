#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % (1000000007);
        a = a * a % (1000000007);
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
    int pow = 1;
    for (int i = 0; i < l ; i++) {
        char k;
        cin >> k;
        v[i] = k == '1';
        if (v[i]) {
            vi += pow;
        }
        pow *= 2;
    }
    vector<bool> m(t);
    pow = 1;
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
        pow *= 2;
    } 

    int tmask = mask;
    

    int n = l;
    int k = binpow(2, t+1);
    cout << "vi = " << tos(vi) << endl;
    vector<vector<long long>> dp(l, vector<long long>(binpow(2, t+1), LLONG_MAX));
    long long temp = vi & mask;
    cout << temp << " " << mask << endl; 
    dp[0][temp] = 0; 
    /*
    for (int i = 0 ; i < l-t ; i++) {
        dp[i][(vi & mask) >> i] = countz((vi & mask) >> i);
        mask = mask << 1;
    }*/
    mask = tmask;

    //cout << "n = " << n << endl;
    //cout << "m = " << k << endl;
    for (int i = 0 ; i < n-1 ; i ++) {
        //cout << "i == " << i << endl;
        for (int j = 0 ; j < k ; j ++) {
            if (dp[i][j] == LLONG_MAX) {
                continue;
            } 
            cout << dp[i][j] << endl;
            int temp = j;
            
            int go = dp[i][j] + countz(temp);
            //cout << "i,j " << i << " " << j << endl;
            long long num = (temp << (t-1)) + ((vi >> (l - (i+t+t-1))) & (mask >> 1));
            //cout << tos(temp << (t-1)) << " | " << tos((vi >> (l - (i+t+t-1))) & (mask >> 1)) << " = " << tos(num) << endl;
            go -= temp & 1;
            temp /= 2;
            int ind = t-1;
            for (int p = t ; p >= 0 ; p--) {
                if (i+p >= n) continue;
                int tmask = mask;
                if (i+p+t >= n) {
                    tmask = tmask >> (i+p+t-n+1);
                }
                int newn = 0;
                newn = (num ^ mi) & tmask;
                //cout << tos(num, t+p) << " " << tos(newn, t) << " " << (countz(num) - countz(num & tmask)) << endl;
                //cout << i+p << " " << newn << " " << (dp[i][j] + (countz(num) - countz(num & tmask))) << endl;
                dp[i+p][newn] = min(dp[i+p][newn], dp[i][j] + (countz(num) - countz(num & tmask)));
                num /= 2;
            }

            //do not place
            //num = (j << 1) + v[i+t+1];
            dp[i+1][num] = min(dp[i+1][num], dp[i][j] + (j & (1 << (t-1))));
        }
    } 

    long long ans = INT_MAX;
    for (int i = 0 ; i < k ; i++) {
        if (dp[n-1][i] != LLONG_MAX) {
            ans = min(ans, dp[n-1][i]);
        }
    }
    cout << ans << endl;

}