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
    int v,e;
    cin >> v >> e;
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

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, Compare> pq;
    pq.push(pair<long long, int>{0, 0});
    c[0] = 0;
    while (!pq.empty()) {
        pair<long long, int> p = pq.top();
        pq.pop();

        if (done[p.second]) {
            continue;
        }
        done[p.second] = true;
        
        for (int i = 0 ; i < adj[p.second].size() ; i++) {
            if (!done[adj[p.second][i].first]) {
                if (adj[p.second][i].second < c[adj[p.second][i].first]) {
                    pq.push(pair<long long, int>{adj[p.second][i].second, adj[p.second][i].first});
                    c[adj[p.second][i].first] = adj[p.second][i].second;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0 ; i < v ; i++) {
        ans += c[i];
       // cout << c[i] << endl;
    }
    cout << ans << endl;

}