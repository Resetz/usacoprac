#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include <chrono>

using namespace std;

template <typename T>
class graph {
    public:
    vector<T> V;
    vector<pair<T,T>> E;
    map<T, int> toNum;
    vector<vector<bool>> adj;

    //assuming directed graph + loops
    graph(set<T> V, vector<pair<T,T>> E) {
        adj.resize(V.size(), vector<bool>(V.size(), false));
        auto it = V.begin();
        for (int i = 0; it != V.end(); i++, it++) {
            this->V.push_back(*it);
            //cout << *it << " corresponds to " << i << endl;
            toNum[*it] = i;
        }
        for (int i = 0 ; i < E.size(); i++) {
            adj[toNum[E[i].first]][toNum[E[i].second]] = true;
        }
        this->E = E;
    }

    map<T, vector<T>> graphAsMap() {
        map<T, vector<T>> ret;
        for (int i = 0 ; i < V.size() ; i++) {
            ret[V[i]] = vector<T>();
            for (int j = 0 ; j < V.size() ; j++) {
                if (adj[i][j]) {
                    ret[V[i]].push_back(V[j]);
                }
            }
        }
        return ret;
    }

    vector<vector<bool>> graphAsAdjMatrix() {
        return adj;
    }

    vector<vector<T>> graphAsAdjList() {
        vector<vector<T>> ret;
        ret.resize(V.size(), vector<T>());

        for (int i = 0 ; i < E.size() ; i++) {
            ret[toNum[E[i].first]].push_back(E[i].second);
        }
        return ret;
    }

};

template <typename T>
class weighted_graph: public graph<T> {
    public:
    vector<vector<int>> W;

    //directed weighted graph + loops
    weighted_graph(set<T> V, vector<pair<pair<T,T>, int>> E) : graph<T>(V, toEdgePair(E)) {
        W.resize(V.size(), vector<int>(V.size()));
        for (int i = 0 ; i < E.size() ; i++) {
            int f = this->toNum[E[i].first.first];
            int t = this->toNum[E[i].first.second];
            W[f][t] = E[i].second;
        }
    }

    static vector<pair<int,int>> toEdgePair(vector<pair<pair<T,T>, int>> E) {
        vector<pair<T,T>> ret;
        for (int i = 0 ; i < E.size() ; i++) {
            ret.push_back(E[i].first);
        }
        return ret;
    }
};

vector<int> dijkstra(weighted_graph<int> g, int startVertex) {
    int n = g.V.size();
    vector<int> ret(n, INT_MAX);

    priority_queue<pair<int,int>> pq;
    pq.push(pair<int,int>(0, startVertex));
    while (pq.size() > 0) {
        pair<int,int> p = pq.top();
        pq.pop();
        if (ret[p.second] != INT_MAX) continue;
        
        p.first = -p.first;
        ret[p.second] = p.first;

        for (int i = 0 ; i < n ; i++) {
            if (g.adj[p.second][i] && p.first+g.W[p.second][i] < ret[i]) {
                pq.push({-(p.first + g.W[p.second][i]), i});
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    auto start = chrono::high_resolution_clock::now();

    set<int> V({0,1,2,3,4});
    vector<pair<pair<int,int>,int>> E({
        {{0,1}, 2}, 
        {{0,2}, 3}, 
        {{1,0}, 7}, 
        {{1,2}, 2}, 
        {{1,3}, 1}, 
        {{2,0}, 12}, 
        {{2,1}, 13}, 
        {{2,4}, 18}, 
        {{3,1}, 3}, 
        {{3,4}, 5}, 
        {{4,2}, 10}, 
        {{4,3}, 12}});

    weighted_graph<int> wg(V, E);

    vector<int> res = dijkstra(wg, 1);

    for (int i = 0 ; i < 5 ; i++) {
        cout << i << " " << res[i] << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    
    cout << "exec time: " << duration.count() << "ms" << endl;
}