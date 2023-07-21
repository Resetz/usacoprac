#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> res;

int dijkstra(vector<vector<pair<int,int>>> &adj) {
    //adj;
    priority_queue<pair<int,int>> pq;
    pq.push({0,0});
    while (pq.size() > 0) {
        pair<int,int> p = pq.top();
        pq.pop();

        p.first *= -1;
        if (res[p.second] != -1) {
            res[p.second] = p.first;
            for (int i = 0 ; i < adj[p.second].size() ; i++) {
                if (res[adj[p.second][i].first] == -1) {
                    pq.push({-(p.first+adj[p.second][i].second), adj[p.second][i].first});
                }
            }
        }
    }
    return res[res.size()-1];
} 

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> A(n, vector<pair<int,int>>(m));
    vector<vector<pair<int,int>>> B(n, vector<pair<int,int>>(m));
    for (int i = 0 ; i < m ; i++) {
        int f,t,a,b;
        cin >> f >> t >> a >> b;
        A[f].push_back({t,a});
        B[f].push_back({t,b});
    }


    vector<vector<int>> weights(n, vector<int>(n, 2));
    res.resize(n,0);
    dijkstra(A);
    //reconstruct path;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < A[i].size() ; j++) {
            if (res[A[i][j].first] - A[i][j].second == res[i]) {
                weights[i][A[i][j].first]--;
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    res.resize(n,0);
    dijkstra(B);
    //reconstruct path;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < B[i].size() ; j++) {
            if (res[B[i][j].first] - B[i][j].second == res[i]) {
                weights[i][B[i][j].first]--;
            }
        }
    }

    res.resize(n,0);

    priority_queue<pair<int,int>> pq;
    pq.push({0,0});
    while (pq.size() > 0) {
        pair<int,int> p = pq.top();
        pq.pop();

        p.first *= -1;
        if (res[p.second] != -1) {
            res[p.second] = p.first;
            for (int i = 0 ; i < n ; i++) {
                if (res[i] == -1) {
                    pq.push(pair<int,int>{-(p.first+weights[p.second][i]), i});
                }
            }
        }
    }
    cout << res[n-1] << endl;
    


}