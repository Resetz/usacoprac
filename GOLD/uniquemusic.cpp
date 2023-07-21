#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

int n, m, k;
vector<vector<int>> v;
vector<pair<int,int>> va;
vector<long long> cnt;

vector<long long> prec;
/*
long long go(int p) {
    if (prec[va[p].first]) {
        return prec[va[p].first];
    }
    vector<long long> dp(k, 0);
    dp[va[p].first-1] = 1;
    for (int i = 0 ; i < k ; i++) {
        if (dp[i] != 0) {
            for (int j = 0 ; j < n ; j++) {
                if (i+va[j].first < k) dp[i+va[j].first] += dp[i];
            }
        }
    }
    //cout << p << " " << dp[k-1] << endl;
    prec[va[p].first] = dp[k-1] % (1000000007);
    return dp[k-1] % (1000000007);
}  
*/
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

int main() {
    cin >> n >> m >> k;

    v.resize(n, vector<int>());
    va.resize(n);
    for (int i = 0 ; i < n ; i++) {
        int a, b;
        cin >> a >> b;
        b--;
        v[b].push_back(a);
        va[i] = {a,b};
    }

    vector<long long> l(26, 0);
    for (int i = 0 ; i < m ; i++) {
        char c;
        cin >> c;
        l[c-'A']++;
    }

    cnt.resize(n, 0);

    vector<long long> dp(k+1, 0);
    dp[0] = 1;
    for (int i = 0 ; i < k ; i++) {
        if (dp[i] == 0) continue;
        for (int j = 0 ; j < n ; j++) {
            if (i + va[j].first <= k) {
                dp[i+va[j].first] = (dp[i+va[j].first] + dp[i]) % (1000000007);
            }
        }
    }

    for (int i = 0 ; i < n ; i++) {
        cnt[va[i].second] = (cnt[va[i].second] + dp[k-va[i].first]) % (1000000007);
        //cout << i << " " << dp[k-va[i].first] << endl;
    }



    long long ans = 1;
    for (int i = 0 ; i < 26 ; i++) {
        if (l[i] == 0) continue;
        long long run = 0;
        for (int j = 0 ; j < n ; j++) {
            //cout << cnt[j] << " " << l[j] << " " << binpow(cnt[j], l[i]) << endl;
            run = (run + binpow(cnt[j], l[i])) % (1000000007);
        }
        ans = ans * run % (1000000007);
    }
    cout << ans << endl;
}