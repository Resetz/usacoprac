#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<long long>> mmult(vector<vector<long long>> a, vector<vector<long long>> b) {
    int n = a.size();
    vector<vector<long long>> res(n, vector<long long>(n));
    
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            long long ans = LLONG_MAX;
            for (int k = 0 ; k < n ; k++) {
                ans = min(ans, a[i][k] + b[k][j]);
            }
            res[i][j] = ans;
        }
    }
    return res;
}

/*
long long binpow(long long x, long long y) {
    if (y <= 0) return 1;
    else if (y % 2 == 1) return (x * binpow(x,y-1) + MOD) % MOD;
    else return (binpow((x*x + MOD) % MOD, y/2) + MOD) % MOD;
}
*/
vector<vector<long long>> mbinpow(vector<vector<long long>> a, int b) {
    if (b == 1) {
        return a; 
    } else if (b % 2 == 0) {
        vector<vector<long long>> res = mbinpow(a, b/2);
        return mmult(res, res);
    } else {
        vector<vector<long long>> res = mbinpow(a, b/2);
        return mmult(a, mmult(res, res));
    }
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<vector<int>> adj(n, vector<int>());
    vector<pair<int,int>> adj2;
    for (int i = 0 ; i < m ; i++) {
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
        adj2.push_back({f,t});
        adj2.push_back({t,f});
    }

    vector<vector<vector<long long>>> other(n, vector<vector<long long>>(n, vector<long long>(n, LLONG_MAX)));
    other[0][0][0] = 0;
    for (int T = 1 ; T < n ; T++) {
        for (int i = 0 ; i < n ; i++) {
            if (other[T-1][i][i] != LLONG_MAX) other[T][i][i] = other[T-1][i][i] + v[(i + T) % n];
        }

        for (int i = 0 ; i < adj2.size() ; i++) {
            for (int j = 0 ; j < n ; j++) {
                other[T][j][adj2[i].second] = min(other[T][j][adj2[i].second], other[T-1][j][adj2[i].first] + v[(i + T) % n]);
            }
        }
    }
    

    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(n, 0)));
    for (int T = 1 ; T < n ; T++) {
        for (int i = 0 ; i < n ; i++) {
            if (dp[T-1][i][i] != LLONG_MAX) dp[T][i][i] = dp[T-1][i][i] + v[(i + T) % n];
        }

        for (int i = 0 ; i < adj2.size() ; i++) {
            for (int j = 0 ; j < n ; j++) {
                dp[T][j][adj2[i].second] = min(dp[T][j][adj2[i].second], dp[T-1][j][adj2[i].first] + v[(i + T) % n]);
            }
        }
    }

    //expo
    if (t/n == 0) {
        long long ans = LLONG_MAX;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                ans = min(ans, other[t][i][j]);
            }
        }
        cout << ans << endl;
    } else {
        vector<vector<long long>> go = mbinpow(dp[n-1], t/n);
        long long ans = LLONG_MAX;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                ans = min(ans, go[i][j] + dp[t%n][i][j]);
            }
        }
        cout << ans << endl;
    }

}