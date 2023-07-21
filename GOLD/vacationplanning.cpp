#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int n,m,k,q;
    cin >> n >> m >> k >> q;

    vector<vector<pair<int,int>>> adj;
    adj.resize(n, vector<pair<int,int>>());
    for (int i = 0 ; i < m ; i++) {
        int f,t,c;
        cin >> f >> t >> c;
        f--;t--;
        adj[f].push_back({t,c});
    }

    vector<vector<long long>> shortest(n, vector<long long>(n, -1));
    for (int i = 0 ; i < n ; i++) {
        //perform dijkstra
        priority_queue<pair<long long,long long>> pq;
        pq.push({0, i});
        while (!pq.empty()) {
            pair<long long,long long> p = pq.top();
            pq.pop();
            if (shortest[i][p.second] != -1) continue;

            p.first = -p.first;
            shortest[i][p.second] = p.first;
            //cout << "- " << i << " " << p.first << " " << p.second << endl;
            for (int j = 0 ; j < adj[p.second].size() ; j++) {
                //cout << i << " " << adj[p.second][j].first << endl;
                if (shortest[i][adj[p.second][j].first] == -1) {
                    pq.push({-(p.first + adj[p.second][j].second), adj[p.second][j].first});
                }
            }
        }
    }

    //cout << "end" << endl;
    long long total = 0;
    int numtotal = 0;
    for (int i = 0 ; i < q ; i++) {
        int f,t;
        cin >> f >> t;
        f--;t--;
        long long found = LONG_MAX;
        for (int j = 0 ; j < k ; j++) {
            if (shortest[f][j] == -1 || shortest[j][t] == -1) continue;
            found = min(shortest[f][j] + shortest[j][t], found);
        }
        if (found != LONG_MAX) {
            total += found;
            numtotal++;
        }
    } 
    cout << numtotal << endl;
    cout << total << endl;
}