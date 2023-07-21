#include <iostream>
#include <vector>
#include <set>

using namespace std;
int n,m;
vector<vector<int>> adj;
vector<bool> vis;

int nodes = 0;
int edges = 0;
void dfs(int x) {
    if (vis[x]) return;
    nodes++;
    edges += adj[x].size();
}


int main() {
    cin >> n >> m;

    adj.resize(n, vector<int>());
    vis.resize(n);

    for (int i = 0; i < m ;i++) {
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
    
    for (int i = 0 ; i < n ; i++) {
        
    }
}