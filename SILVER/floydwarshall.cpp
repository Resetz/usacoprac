#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m,q;

    cin >> n >> m >> q;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<bool>> dist(n, vector<bool>(n, false));
    for (int i = 0 ; i < m ; i++) {
        int f,t;
        cin >> f >> t;
        f--; t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
        dist[t][f] = true;
        dist[f][t] = true;
    }


    for (int k = 0 ; k < n ; k++) {
        for (int i = 0 ; i < n ; i++) {
            if (k == i) continue;
            if (!dist[i][k]) continue;
            for (int j = 0 ; j < n ; j++) {
                if (j == i || j == k) continue;
                dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]);
            }
        }
    }

    for (int i = 0 ; i < q ; i++) {
        int f, t;
        cin >> f >> t;
        f--; t--;
        cout << (dist[f][t] ? 'Y' : 'N') << endl;
    }
}