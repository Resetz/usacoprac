#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> m >> n;

    string s;
    cin >> s;

    vector<string> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<vector<int>> adj(m, vector<int>());
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (j + v[i].size() - 1 >= m) break;
            bool good = true;
            for (int k = 0 ; k < v[i].size() ; k++) {
                if (s[j+k] == '?') {
                    continue;
                } else {
                    if (!(good = (s[j+k] == v[i][k]))) {
                        break;
                    }
                }
            }
            if (good)
            adj[j].push_back(i);
        }
    }

    vector<string> dp(m+1);
    vector<bool> vis(m, false);
    dp[0] = "";
    vis[0] = true;
    string cur = "";
    for (int i = 0 ; i <= m ; i++) {
        dp[i] = cur;
        cur += 'z';
    }

    //for (int it = 0 ; it < n ; it++) {
        for (int i = 0 ; i < m ; i++) {
            if (!vis[i]) continue;
            for (int j = 0 ; j < adj[i].size() ; j++) {
                if (i+v[adj[i][j]].size() >= m+1) continue;
                if ((dp[i] + v[adj[i][j]]) < dp[i+v[adj[i][j]].size()]) {
                    dp[i+v[adj[i][j]].size()] = dp[i] + v[adj[i][j]];
                    vis[i+v[adj[i][j]].size()] = true;
                }
            }
        }
    //}
    cout << dp[m] << endl;
}