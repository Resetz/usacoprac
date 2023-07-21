/*

Implementation file for graph library.

*/
#include <vector>
#include <set>
#include <climits>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

template <typename T>
graph<T>::graph(set<T> V, vector<pair<T,T>> E) {
    // Initialize Array
    adj.resize(V.size(), vector<bool>(V.size(), false));
    auto it = V.begin();
    for (int i = 0; it != V.end(); i++, it++) {
        this->V.push_back(*it);
        toNum[*it] = i;
    }
    for (int i = 0 ; i < E.size(); i++) {
        adj[toNum[E[i].first]][toNum[E[i].second]] = true;
    }
    this->E = E;
}
    /* graph(set<T> V)
     **************************************************************************
     * Purpose: Initialize a directed graph with a given set of vertices.
     **************************************************************************
     * Parameters:
     *  - set<T> V : A set of vertices to be included in the graph.
     **************************************************************************/
template <typename T>
graph<T>::graph(set<T> V) {
    adj.resize(V.size(), vector<bool>(V.size(), false));

    auto it = V.begin();
    for (int i = 0; it != V.end(); i++, it++) {
        this->V.push_back(*it);
        //cout << *it << " corresponds to " << i << endl;
        toNum[*it] = i;
    }
    this->E = vector<pair<T, T>>(0);
}

template <typename T>
map<T, vector<T>> graph<T>::graphAsMap() {
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

template <typename T>
vector<vector<bool>> graph<T>::graphAsAdjMatrix() {
    return adj;
}

template <typename T>
vector<vector<T>> graph<T>::graphAsAdjList() {
    vector<vector<T>> ret;
    ret.resize(V.size(), vector<T>());

    for (int i = 0 ; i < E.size() ; i++) {
        ret[toNum[E[i].first]].push_back(E[i].second);
    }
    return ret;
}


template <typename T>
weighted_graph<T>::weighted_graph(set<T> V, vector<pair<T,T>> E, vector<vector<int>> W): graph<T>(V,E) {
    this->W = W;
}

template <typename T>
weighted_graph<T>::weighted_graph(set<T> V, vector<pair<pair<T,T>, int>> W): graph<T>(V) {
    this->W.resize(V.size(), vector<int>(V.size()));
    for (int i = 0 ; i < W.size() ; i++) {
        pair<pair<T,T>, int> cur = W[i];
        this->W[this->toNum[W[i].first.first]][this->toNum[W[i].first.second]] = cur.second;
        
        this->E.push_back(cur.first);
        this->adj[this->toNum[cur.first.first]][this->toNum[cur.first.second]] = true;
    }
}

vector<graph<int>> allGraphs(int n) {
    vector<pair<int,int>> edges;
    set<int> vert;
    for (int i = 0 ; i < n ; i++) {
        vert.insert(i);
        for (int j = i+1 ; j < n ; j++) {
            edges.push_back({i,j});
        }
    }
    
    vector<graph<int>> ret;
    int nedges = n*(n-1)/2;
    int k = (int) pow(2, nedges);
    for (int i = 0 ; i < k ; i++) {
        vector<pair<int,int>> e;
        for (int j = 0 ; j < nedges ; j++) {
            if ((i >> j) & 1) {
                e.push_back(edges[j]);
                e.push_back({edges[j].second, edges[j].first});
            }
        }
        //cout << i << " " << e.size() << endl;
        ret.push_back(graph<int>(vert, e));
    }
    return ret;
}

template<typename T>
map<T,int> dijkstra(weighted_graph<T> g, T startVertex) {
    int n = g.V.size();
    map<T, int> ret;
    for (T x : g.V) {
        ret[x] = INT_MAX;
    }

    priority_queue<pair<int,T>> pq;
    pq.push(pair<int,T>(0, startVertex));
    while (pq.size() > 0) {
        pair<int,T> p = pq.top();
        pq.pop();
        if (ret[p.second] != INT_MAX) continue;

        // Edge weight is negative to prioritize lowest edge weight.
        // * C++ priority queue prefers highest value to be first.
        int curdist = -p.first;
        T curvert = p.second;

        // Set answer in ret.
        ret[curvert] = curdist;

        // Check to see if graph contains the edge curvert->x
        for (T x : g.V) {
            if (g.adj[g.toNum[curvert]][g.toNum[x]] && 
                p.first+g.W[g.toNum[curvert]][g.toNum[x]] < ret[x]) {
                pq.push({-(curdist + g.W[g.toNum[curvert]][g.toNum[x]]), x});
            }
        }
    }
    return ret;
}