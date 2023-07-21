#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());
    for (int i = 0 ; i < n-1 ; i++) {
        int f,t;
        cin >> f >> t;
        f--; t--;
        adj[f].push_back({t,i});
        adj[t].push_back({f,i});
    }

    priority_queue<pair<pair<int,int>,int>> pq;
    pq.push({{0,1}, 0});
    vector<int> vis(n);
    int ans = 0;
    while (pq.size() > 0) {
        pair<pair<int,int>,int> p = pq.top();
        pq.pop();
        if (vis[p.second]++) continue;

        int cycle = -p.first.first;
        ans = max(cycle, ans);
        int time = -p.first.second;
        for (int i = 0 ; i < adj[p.second].size() ; i++) {
            if (!vis[adj[p.second][i].first]) {
                if (adj[p.second][i].second > time) {
                    pq.push({{-cycle, -adj[p.second][i].second}, adj[p.second][i].first});
                } else {
                    pq.push({{-cycle-1, -adj[p.second][i].second}, adj[p.second][i].first});
                }
            }
        }
    }
    cout << ans+1 << endl;
}

int main() {
    int n; cin >> n;
    while (n--) solve();
}