#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0 ; i < m ; i++) {
        int f,t,l;
        cin >> f >> t >> l;
        f--; t--;
        adj[f].push_back({t,l});
        adj[t].push_back({f,l});
    }

    priority_queue<pair<int,pair<int,int>>> pq;
    vector<int> fruit(n, -1);
    for (int i = 0 ; i < k ; i++) {
        int a,b; cin >> a >> b;
        a--;
        fruit[a] = max(fruit[a], b);
    }

    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>> dijk;
    vector<int> mst(n, 0);
    vector<int> vis(n, false);


    dijk.push({0, n-1});
    while (dijk.size() > 0) {
        pair<int,int> p = dijk.top();
        dijk.pop();

        if (!vis[p.second]) {
            vis[p.second] = true;
        } else {
            continue;
        }
        p.first *= -1;
        for (int i = 0 ; i < adj[p.second].size(); i++) {
            pair<int,int> e = adj[p.second][i];
            if (dist[e.first] >= p.first + e.second) {
                
                dist[e.first] = p.first + e.second;
                mst[e.first] = p.second;
                dijk.push({-(p.first + e.second), e.first});
            }
        }
    }


    vector<int> donutdist(n, INT_MAX);
    vector<int> donutnum(n, INT_MAX);
    for (int i = 0 ; i < fruit.size() ; i++) {
        //cout << dist[i] << endl;
        if (fruit[i] != -1) {
            pq.push({fruit[i]/* - dist[i]*/ - dist[i], {i, i}});
            //cout << "f " << i << " " << fruit[i] << " " << dist[i] <<  endl;
           // cout << "F " << fruit[i] << endl;
            
        }
    }
    while (pq.size() > 0) {
        pair<int,pair<int,int>> p = pq.top();
        pq.pop();
        
        int rem = p.first;
        int cur = p.second.first;
        int ori = p.second.second;
        if (donutnum[cur] != INT_MAX) continue;
        donutdist[cur] = rem;
        donutnum[cur] = ori;
       //cout << "donut " << rem << " " << cur << " " << ori << endl;
        for (int i = 0 ; i < adj[cur].size() ; i++) {
            pair<int,int> e = adj[cur][i];
            if (rem-e.second <= donutdist[e.first]) {
                pq.push({rem-e.second, {e.first, ori}});
            } 
        }
    }

    adj.clear();
    adj.resize(n, vector<pair<int,int>>());
    for (int i = 0 ; i < n-1 ; i++) {
        //cout << i << " " << mst[i] << endl;
        adj[mst[i]].push_back({i, 0});
    }
    queue<pair<int,int>> bfs;
    bfs.push({n-1, false});
    vector<int> ans(n, false);
    while (bfs.size() > 0) {
        pair<int,int> p = bfs.front();
        bfs.pop();
        if (donutdist[p.first] != INT_MAX) {
            //cout << p.first << " " << donutdist[p.first] << " " << dist[donutnum[p.first]] << " <= " << dist[p.first] << endl;
            if ( -donutdist[p.first] <= dist[p.first]) p.second = true;
        }
        ans[p.first] |= p.second;
        //cout << p.first << " " << p.second << endl;
        for (int i = 0 ; i < adj[p.first].size() ; i++) {
            bfs.push({adj[p.first][i].first, p.second});
        }
    }

    //cout << "here" << endl;
    for (int i = 0 ; i < n-1 ; i++) {
        cout << (ans[i] ? "1" : "0") << endl;
    }

}