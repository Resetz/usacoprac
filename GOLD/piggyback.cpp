#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int b,e,p,n,m;
    cin >> b >> e >> p >> n >> m;

    vector<vector<int>> adj(n, vector<int>());
    vector<int> step(3);
    step = {b,e,p};
    for (int i = 0 ; i < m ; i++) {
        int f,t;
        cin >> f >> t; f--;t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    vector<vector<int>> dist(3, vector<int>(n, -1));
    for (int i = 0 ; i < 3; i++) {
        queue<pair<int,int>> q;
        if (i == 0) {
            q.push({0, 0});
        } else if (i == 1) {
            q.push({0,1});
        } else {
            q.push({0,n-1});
        }
        vector<int> &vis = dist[i];
        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            
            vis[p.second] = p.first;
           // cout << i << " -> " << p.second << " " << p.first << endl;
            for (int j = 0 ; j < adj[p.second].size() ; j++) {
                if (vis[adj[p.second][j]] == -1) {
                    vis[adj[p.second][j]] = p.first+1;
                    q.push({p.first+1, adj[p.second][j]});
                }
            }
        }
       // cout << endl;
    }
    int sum = INT_MAX;
    for (int i = 0 ; i < n ; i++) {
        int cur = 0;
        for (int j = 0; j < 3 ; j++) {
            cur += dist[j][i] * step[j];
        }
        sum = min(sum, cur);
    }
    cout << sum << endl;
}