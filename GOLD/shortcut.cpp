#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n,m,t;
    cin >> n >> m >> t;
    vector<int> c(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> c[i];
    }

    vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());
    for (int i = 0 ; i < m ; i++) {
        int f,t,w;
        cin >> f >> t >> w;
        f--;t--;
        adj[f].push_back({t, w});
        adj[t].push_back({f, w});
    }

    vector<int> dist(n, -1);
    vector<int> par(n, -1);
    vector<int> l(n, -1);
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({0,{0,-1}});
    while (!pq.empty()) {
        pair<int,pair<int,int>> p = pq.top();
        pq.pop();
        p.first *= -1;
        if (dist[p.second.first] == -1) {
            dist[p.second.first] = p.first;
            par[p.second.first] = p.second.second;
            for (int i = 0 ; i < adj[p.second.first].size() ; i++) {
                if (dist[adj[p.second.first][i].first] == -1 || p.first + adj[p.second.first][i].second <= dist[adj[p.second.first][i].first]) {
                    pq.push({-(p.first + adj[p.second.first][i].second), {adj[p.second.first][i].first, p.second.first}});
                }
            }
        }
        if (p.second.second < par[p.second.first] && dist[p.second.first] == p.first) {
            par[p.second.first] = p.second.second;
            continue;
        }
    }
   // cout << "out" << endl;
    vector<pair<int,int>> a(n);
    vector<int> cnt(n, 0);
    for (int i = 1 ; i < n ; i++) {
        a[i] = {par[i], dist[i] - dist[par[i]]};
    }

    for (int i = 0 ; i < n ; i++) {
        //cout << dist[i] << " ";
        int cur = i;
        while (cur != -1) {
            cnt[cur] += c[i];
            cur = par[cur];
        }
    }
   // cout << endl;
    for (int i = 0 ; i < n ; i++) {
        //cout << cnt[i] << " ";
    }
    //cout << endl;

    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        ans = max(ans, cnt[i] * (dist[i]-t));
    }
    cout << ans << endl;
}