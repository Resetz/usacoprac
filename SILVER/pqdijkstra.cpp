#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Compare
{
public:
    bool operator() (pair<long long,int> a, pair<long long,int> b)
    {
        return a.first > b.first;
    }
};

int main() {
    int v,e,s;
    cin >> v >> e >> s;
    s--;
    vector<vector<pair<int, long long>>> adj(v, vector<pair<int, long long>>());
    for (int i = 0 ; i < e ; i++) {
        int f,t,c;
        cin >> f >> t >> c;
        f--;t--;
        adj[f].push_back(pair<int,long long>{t, c});
        adj[t].push_back(pair<int,long long>{f, c});
    }

    vector<bool> done(v, false);
    vector<long long> c(v, LLONG_MAX);
    c[s] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, Compare> pq;
    pq.push(pair<long long, int>{0, s});
    while (!pq.empty()) {
        pair<long long, int> p = pq.top();
        pq.pop();

        if (done[p.second]) {
            continue;
        }
        done[p.second] = true;
        
        for (int i = 0 ; i < adj[p.second].size() ; i++) {
            if (!done[adj[p.second][i].first]) {
                if (p.first+adj[p.second][i].second < c[adj[p.second][i].first]) {
                    pq.push(pair<long long, int>{p.first+adj[p.second][i].second, adj[p.second][i].first});
                    c[adj[p.second][i].first] = p.first+adj[p.second][i].second;
                }
            }
        }
    }
    for (int i = 0 ; i < v ; i++) {
        if (c[i] == LLONG_MAX) {
            cout << -1 << endl;
        } else {
            cout << c[i] << endl;
        }

    }

}