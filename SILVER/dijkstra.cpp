#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

class Compare
{
public:
    bool operator() (pair<int,int> a, pair<int,int> b)
    {
        return a.first > b.first;
    }
};

int main() {
    int v,e,s;
    cin >> v >> e >> s;
    s--;
    vector<vector<int>> adj(v, vector<int>(v,-1));

    for (int i = 0 ; i < e;  i++) {
        int f,t,l;
        cin >> f >>t >> l;
        f--;
        t--;
        adj[f][t] = l;
        adj[t][f] = l;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
    pq.push(pair<int,int>{0,s});
    vector<int> ans(v, -1);

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
}