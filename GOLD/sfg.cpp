#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class dsu {
    public:
    vector<int> parent;
    vector<int> s;
    vector<int> m;
    int size = 0;
    dsu(int n) {
        parent.resize(n);
        s.resize(n, 1);
        m.resize(n, 1);
        size = n;
        for (int i = 0 ; i < n ; i++) parent[i] = i;
    }

    int find_set(int a) {
        if (a == parent[a])
            return a;
        return parent[a] = find_set(parent[a]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (s[a] < s[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            s[a] += s[b];
            m[a] = min(m[a], m[b]);
            size--;
        }
    }

    int find_size(int a) {
        return s[find_set(a)];
    }
};

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0 ; i < m ; i++) {
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    priority_queue<pair<int,int>> pq;
    vector<int> neighbors(n, 0);
    for (int i = 0 ; i < n ; i++) {
        pq.push({-adj[i].size(), i});
        neighbors[i] = adj[i].size();
        //cout << i << ": " << neighbors[i] << endl;
    }
    
    vector<vector<int>> rounds;
    vector<int> roundn;
    vector<bool> vis;
    vector<int> roundt;
    roundt.resize(n);
    vis.resize(n, false);
    int cur;
    int o = 0;
    while (pq.size() > 0) {
        while (pq.size() > 0) {
            pair<int,int> p = pq.top();
            if (vis[p.second]) {
                pq.pop();
                continue;
            } else {
                break;
            }
        }
        if (pq.size() < 0) break;
        cur = -pq.top().first;
        rounds.push_back(vector<int>());
        roundn.push_back(cur);
        while (pq.size() > 0 && -pq.top().first <= cur) {
            pair<int,int> p = pq.top();
            pq.pop();

            if (vis[p.second]) continue;
            vis[p.second] = true;

            rounds[o].push_back(p.second);
            roundt[p.second] = o;
            for (int i = 0 ; i < adj[p.second].size() ; i++) {
                if (!vis[adj[p.second][i]]) {
                    pq.push({-(--neighbors[adj[p.second][i]]), adj[p.second][i]});
                }
            }
        }
        o++;
    }

    dsu d(n);
    vis.clear();
    vis.resize(n, false);
    long long ans = 0;
    for (int i = rounds.size()-1; i >= 0 ; i--) {
        for (int j = 0 ; j < rounds[i].size() ; j++) {
            cur = rounds[i][j];
            for (int k = 0 ; k < adj[cur].size() ; k++) {
                if (roundt[adj[cur][k]] >= i) {
                    d.union_set(cur, adj[cur][k]);
                    ans = max(ans, (long long)d.find_size(adj[cur][k]) * roundn[i]);
                }
            }
        }
    }
    cout << ans << endl;
}