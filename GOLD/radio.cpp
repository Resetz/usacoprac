#include <iostream>
#include <vector>

using namespace std;

long long dist(pair<int,int> a, pair<int,int> b) { 
    return ((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main() {
    int n, m;
    cin >> n >> m;

    pair<int,int> fj;
    pair<int,int> bs;
    cin >> fj.first >> fj.second;
    cin >> bs.first >> bs.second;

    vector<pair<int,int>> f(n+1);
    f[0] = fj;
    vector<pair<int,int>> b(m+1);
    b[0] = bs;
    for (int i = 0 ; i < n ; i++) {
        char c;
        cin >> c;
        int up = 0;
        int right = 0;
        if (c == 'N') {
            up = 1;
        } else if (c == 'S') {
            up = -1;
        } else if (c == 'E') {
            right = 1;
        } else{
            right = -1;
        }
        f[i+1] = {f[i].first+right, f[i].second+up};
        //cout << f[i+1].first << " " << f[i+1].second << endl;
    }

    for (int i = 0 ; i < m ; i++) {
        char c;
        cin >> c;
        int up = 0;
        int right = 0;
        if (c == 'N') {
            up = 1;
        } else if (c == 'S') {
            up = -1;
        } else if (c == 'E') {
            right = 1;
        } else{
            right = -1;
        }
        b[i+1] = {b[i].first+right, b[i].second+up};
        //cout << b[i+1].first << " " << b[i+1].second << endl;
    }

   // cout << "here" << endl;
    
    vector<vector<long long>> dp(n+1, vector<long long>(m+1));

    for (int i = 1 ; i <= m ; i++) {
        dp[0][i] = dp[0][i-1] + dist(b[i], f[0]);
    }
    for (int i = 1 ; i <= n ; i++) {
        dp[i][0] = dp[i-1][0] + dist(b[0], f[i]);
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + dist(f[i], b[j]);
           // cout << "{" << f[i].first << ", " << f[i].second << "} {" << b[j].first << ", " << b[j].second << "} = " << dist(f[i], b[j]) << endl;
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[n][m] << endl;
}