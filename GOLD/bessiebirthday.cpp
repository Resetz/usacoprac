#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<int> v(n);
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
        int k;
        cin >> k;
        for (int j = 0 ; j < k ; j++) {
            int to = 0;
            cin >> to;
            to--;
            adj[i].push_back(to);
            adj[to].push_back(i);
        }
    }

    vector<vector<pair<int,int>>> reach(n, vector<pair<int,int>>());
    for (int i = 0 ; i < n ; i++) {
        int k;
        vector<int> dist(n, -2);
        queue<pair<int,int>> q;
        dist[i] = 0;
        q.push({i, 0});
        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            for (int j = 0 ; j < adj[p.first].size() ; j++) {
                if (dist[adj[p.first][j]] == -2) {
                    if (v[adj[p.first][j]] > v[i]) {
                        dist[adj[p.first][j]] = p.second+1;
                    } else {
                        dist[adj[p.first][j]] = -1;
                    }
                    q.push({adj[p.first][j], p.second+1});
                } 
            }
        }
        for (int j = 0 ; j < n ; j++) {
            if (dist[j] > 0) {
                //cout << i << "->" << j << " " << v[j]-dist[j]*e << " " << dist[j] << endl;
                reach[i].push_back({j, v[j]-dist[j]*e});
            }
        }
    }

    vector<int> dp(n, 0);
    vector<int> cur(n, 0);
    for (int i = 0; i < n ; i++) {
        dp[i] = v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            for (int k = 0 ; k < reach[j].size() ; k++) {
                cur[reach[j][k].first] = max(cur[reach[j][k].first], dp[j]+reach[j][k].second);
               // cout << j << " " << reach[j][k].first << " | " << cur[reach[j][k].first] << endl;
            }
        }
        dp = cur;
        for (int j = 0 ; j < n ; j++) {
            dp[j] = max(0, dp[j]);
            cur[j] = max(0, cur[j]);
        }
    }
    int ans = 0;
    for (int i = 0 ; i < n ; i++) { 
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
}