#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

template <typename T>
class graph {
    public:
    vector<T> V;
    map<T, int> toNum;
    vector<vector<bool>> adj;

    //assuming directed graph + loops
    graph(set<T> V, vector<pair<T,T>> E) {
        adj.resize(V.size(), vector<bool>(V.size(), false));
        for (int i = 0, set<int>::iterator it = V.begin(); it != V.end(); i++, it++) {
            V.push_back(*it);
            toNum[*it] = i;
        }
        for (int i = 0 ; i < E.size(); i++) {
            adj[toNum[E[i].first]][toNum[E[i].second]] = true;
        }
    }

    map<T, vector<T>> graphAsMap() {
        map<T, vector<T>> ret;
        for (int i = 0 ; i < V.size() ; i++) {
            ret[V[i]] = vector<T>();
            for (int j = 0 ; i < V.size() ; i++) {
                if (adj[i][j]) {
                    ret[V[i]].push_back(V[j]);
                }
            }
        }
        return ret;
    }

    vector<vector<int>> graphAsAdjMatrix() {
        return adj;
    }

    vector<vector<int>> graphAsAdjList() {
        vector<vector<T>> ret;
        ret.resize(V.size());

        for (int i = 0 ; i < V.size() ; i++) {
            for (int j = 0 ; j < V.size() ; j++) {
                if (ret[i][j]) {
                    ret[]
                }
            }
        } 
    }
    private:
};