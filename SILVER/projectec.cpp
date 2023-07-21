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

    cout << endl;
    vector<graph<int>> graphs = allGraphs(4);
    cout << "There are " << graphs.size() << " complete graphs." << endl;
    for (int i = 0 ; i < graphs.size() ; i++) {
        vector<vector<bool>> adj = graphs[i].graphAsAdjMatrix();
        for (int j = 0 ; j < 4 ; j ++) {
            for (int k = 0 ; k < 4 ; k ++) {
                cout << adj[j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "allgraphs: exec time: " << duration.count() << "ms" << endl;

    start = chrono::high_resolution_clock::now();
    s.clear();
    s = {'a','b','c','d','e','z'};

    // Writing double edges and weights
    vector<pair<pair<char,char>,int>> W =
    {
        {{'a','b'}, 4},
        {{'b','a'}, 4},
        {{'a','c'}, 2},
        {{'c','a'}, 2},
        {{'b','c'}, 1},
        {{'c','b'}, 1},
        {{'b','d'}, 5},
        {{'d','b'}, 5},
        {{'c','d'}, 8},
        {{'c','d'}, 8},
        {{'c','e'}, 10},
        {{'e','c'}, 10},
        {{'e','d'}, 2},
        {{'d','e'}, 2},
        {{'z','e'}, 3},
        {{'e','z'}, 3},
        {{'d','z'}, 6},
        {{'z','d'}, 6}
    };

    // Intializing Weighted Graph
    weighted_graph<char> wg(s, W);
    
    // Running dijkstra from vertex 'a'
    map<char, int> res = dijkstra(wg, 'a');

    for (char c : s) {
        cout << "Shortest path from a to " << c << " is " << res[c] << endl;
    }
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "dijkstra: exec time: " << duration.count() << "ms" << endl;
}