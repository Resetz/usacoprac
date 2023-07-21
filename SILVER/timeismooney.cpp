#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m >> c;

    vector<long long> cost(n);
    vector<vector<long long>> adj(n, vector<long long>());

    for (int i = 0 ; i < n ; i++) {
        cin >> cost[i];
    }
    for (int i = 0 ; i < m ; i++) {
        int f, t;
        cin >> f >> t;
        f--; t--;
        adj[f].push_back(t);
    }

    vector<long long> dp(n, -1);
    vector<long long> cur(n, -1);
    dp[0] = 0;

    long long ans = 0;

    for (int i = 1 ; i < 1000 ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cur[j] = -1;
        }
        for (int j = 0 ; j < n ; j++) {
            if (dp[j] == -1) continue;
            for (int k = 0 ; k < adj[j].size() ; k++) {
                cur[adj[j][k]] = max(cur[adj[j][k]], dp[j] + cost[adj[j][k]]); 
            }
        }
        
        ans = max(ans, cur[0] - i*i*c);
        dp = cur;
    }
    cout << ans << endl;


}