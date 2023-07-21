
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
    int v,e;
    cin >> v >> e;
    vector<vector<pair<int,int>>> adj(v);

    for (int i = 0 ; i < e;  i++) {
        int f,t,l;
        cin >> f >>t >> l;
        f--;
        t--;
        adj[f].push_back({t,l});
        adj[t].push_back({f,l});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
    pq.push(pair<int,int>{0,0});
    vector<int> ans(v, -1);

    while (!pq.empty()) {
        pair<int,int> p = pq.top();
        pq.pop();
        if (ans[p.second] != -1) {
            continue;
        }
        ans[p.second] = p.first;
        for (int i = 0 ; i < adj[p.second].size(); i++) {
            if (ans[adj[p.second][i].first] == -1) {
                pq.push(pair<int,int>{p.first+adj[p.second][i].second, adj[p.second][i].first});
                //cout << p.second << " -> " << adj[p.second][i].first << endl;
            }
            
        }
    }
    cout << ans[v-1] << endl;
}
/*#include <iostream>
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
    int v,e;
    cin >> v >> e;
    vector<vector<int>> adj(v, vector<int>(v,2147483647));

    for (int i = 0 ; i < e;  i++) {
        int f,t,l;
        cin >> f >>t >> l;
        f--;
        t--;
        adj[f][t] = min(l,adj[f][t]);
        adj[t][f] = min(l,adj[t][f]);
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
    pq.push(pair<int,int>{0,0});
    vector<int> ans(v, -1);

    vector<pair<int,int>> found(v, {0,INT_MAX});
    vector<pair<int,int>> next(v, {0,INT_MAX});
    found[0] = {0,0};
    next[0] = {0,0};

    while(true) {
        bool keep_going = false;
        for (int i = 0 ; i < v ; i++) {
            if (found[i].first != 1 && found[i].second != INT_MAX) {
                keep_going = true;
                //cout << found[i].first << endl;
                for (int j = 0 ; j < v ; j++) {
                    if (found[j].first != 1 && adj[i][j] != INT_MAX) {
                        next[j] = {0, min(next[j].second, next[i].second + adj[i][j])};
                    }
                }
                next[i].first = 1;
            }
        }
        if (!keep_going) break;
        found = next;
    }
    cout << found[v-1].second << endl;
    
}*/