#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <chrono>
#include "projectec_graph.h"

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    auto start = chrono::high_resolution_clock::now();

    set<char> s;
    s.insert('a');
    s.insert('b');
    s.insert('c');
    s.insert('d');
    vector<pair<char,char>> v = {{'a','b'},{'b','c'},{'a','c'},{'c','d'},{'b','d'}};
    graph<char> g(s,v);

    cout << "Representation of Graph as a Adjacency Matrix: " << endl;
    vector<vector<bool>> adj = g.graphAsAdjMatrix();
    for (int i = 0 ; i < 4 ; i ++) {
        for (int j = 0 ; j < 4 ; j ++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Representation of Graph as a Adjacency List: " << endl;
    vector<vector<char>> adjList = g.graphAsAdjList();
    for (int i = 0 ; i < 4 ; i++) {
        cout << i << ": "; 
        for (int j = 0 ; j < adjList[i].size() ; j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Representation of Graph as a Map: " << endl;
    map<char, vector<char>> adjMap = g.graphAsMap();
    for (auto it = s.begin() ; it != s.end() ; it++) {
        cout << *it << ": ";
        for (int j = 0 ; j < adjMap[*it].size() ; j++) {
            cout << adjMap[*it][j] << " ";
        }
        cout << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "graphrep: exec time: " << duration.count() << "ms" << endl;
}