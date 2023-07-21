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
    
    set<char> s = {'a','b','c','d','e','z'};

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
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "dijkstra: exec time: " << duration.count() << "ms" << endl;
}