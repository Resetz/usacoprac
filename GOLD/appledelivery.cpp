#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int m,n,a,b,c;
    cin >> m >> n >> a >> b >> c;
    a--;b--;c--;

    vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());

    for (int i = 0 ; i < m ; i++) {
        int f,t,d;
        cin >> f >> t >> d;
        f--;t--;
        adj[f].push_back({t,d});
        adj[t].push_back({f,d});
    }
    
    vector<vector<int>> dist(3, vector<int>(n, -1));
    for (int i = 0 ; i < 3; i++) {
        priority_queue<pair<int,int>> q;
        if (i == 0) {
            q.push({0, a});
        } else if (i == 1) {
            q.push({0, b});
        } else {
            q.push({0, c});
        }
        vector<int> &vis = dist[i];
        while (!q.empty()) {
            pair<int,int> p = q.top();
            q.pop();
            
            if (vis[p.second] != -1) continue;
            p.first = p.first * -1;

            vis[p.second] = p.first;
            for (int j = 0 ; j < adj[p.second].size() ; j++) {
                if (vis[adj[p.second][j].first] == -1) {
                    q.push({-(p.first+adj[p.second][j].second), adj[p.second][j].first});
                }
            }
        }
    }
    //cout << dist[0][b] << " " << dist[1][c] << endl << dist[0][c] << " " << dist[2][b] << endl;
    cout << min(dist[0][b] + dist[1][c], dist[0][c] + dist[2][b]) << endl;
}