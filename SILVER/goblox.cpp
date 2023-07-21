#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
    int from,to,l;
} tri;

class Compare
{
public:
    bool operator() (tri &a, tri &b)
    {
        return a.l > b.l;
    }
};


int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>(n, -1));

    for (int i = 0; i < m ; i++) {
        int f,t,d;
        cin >> f >> t >> d;
        f--;
        t--;
        adj[f][t] = d;
        adj[t][f] = d;
    }

    priority_queue<tri, vector<tri>, Compare> pq;
    pq.push(tri{-1,0,0});
    vector<int> ans(n,-1);
    vector<int> prev(n,-1);
    while (!pq.empty()) {
        tri t = pq.top();

        pq.pop();

        if (ans[t.to] != -1) {
            continue;
        }

        ans[t.to] = t.l;
        prev[t.to] = t.from;

        for (int i = 0 ; i < n ; i++) {
            if (adj[t.to][i] != -1) {
                if (ans[i] == -1) {
                    pq.push(tri{t.to, i, t.l+adj[t.to][i]});
                }
            }
        }
    }
    int origin = ans[n-1];
    vector<pair<int,int>> path;

    int cur = n-1;
    while (cur != -1) {
        path.push_back(pair<int,int>(prev[cur], cur));
        cur = prev[cur];
    }

   // cout << "here" << endl;


    int best = 0;
    for (int i = 0 ; i < path.size() ; i++) {
        //cout << path[i].first << " " << path[i].second << endl;
        if (path[i].first == -1) continue; 
        adj[path[i].first][path[i].second] *= 2;
        adj[path[i].second][path[i].first] *= 2;
        
        priority_queue<tri, vector<tri>, Compare> pq;
        pq.push(tri{-1,0,0});
        vector<int> ans(n,-1);
        while (!pq.empty()) {
            tri t = pq.top();

            pq.pop();

            if (ans[t.to] != -1) {
                continue;
            }

            ans[t.to] = t.l;

            for (int i = 0 ; i < n ; i++) {
                if (adj[t.to][i] != -1) {
                    if (ans[i] == -1) {
                        pq.push(tri{t.from, i, t.l+adj[t.to][i]});
                    }
                }
            }
        }
        best = max(ans[n-1] - origin, best);
        adj[path[i].first][path[i].second] /= 2;
        adj[path[i].second][path[i].first] /= 2;
    }
    cout << best << endl;
    /*
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
    pq.push(pair<int,int>{0,0});
    vector<int> ans(n, -1);

    vector<int> prev(n, -1);

    while (!pq.empty()) {
        pair<int,int> p = pq.top();
        pq.pop();
        if (ans[p.second] != -1) {
            continue;
        }
        ans[p.second] = p.first;
        for (int i = 0 ; i < v; i++) {
            if (adj[p.second][i] != -1) {
                if (ans[i] == -1) {
                    pq.push(pair<int,int>{p.first+adj[p.second][i], i});
                }
            }
        }
    }

    for (int i = 0; i < v; i++) {
        cout << ans[i] << endl;
    }
    */
}