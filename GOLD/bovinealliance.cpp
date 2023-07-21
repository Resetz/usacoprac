#include <iostream>
#include <vector>
#include<algorithm> 
#include <queue>
#include <set>

using namespace std;

vector<int> visited;
vector<int> edges;
int edge_count = 0;
int node_count = 0;
vector<vector<pair<int,int>>> adj;

int $(int a, int b) {
    return a + b;
}


void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = true;
    node_count++;
    for (int i = 0 ; i < adj[cur].size() ; i++) {
        if (!edges[adj[cur][i].second]) {
            edge_count++;
            edges[adj[cur][i].second] = true;
        }
        if (!visited[adj[cur][i].first]) {
            dfs(adj[cur][i].first);
        }
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    visited.resize(n, false);
    edges.resize(m, false);
    adj.resize(n, vector<pair<int,int>>());
    set<pair<int,int>> s;
    
    for (int i = 0 ; i < m ; i++) {
        int f,t;
        cin >> f >> t;
        if ( f > t ) {
            int temp = f;
            f = t;
            t = temp;
        }

        f--;t--;
        adj[f].push_back({t, i});
        adj[t].push_back({f, i});
    }


    long long ans = 1;
    for (int i = 0 ; i < n ; i++) {
        if (!visited[i]) {
            edge_count = node_count = 0;
            dfs(i);
            if (edge_count == node_count-1) {
                ans = (ans * node_count) % 1000000007;
            } else if( edge_count == node_count ) {
                ans = (ans * 2) % 1000000007;
            } else {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << ans % 1000000007 << endl;
}