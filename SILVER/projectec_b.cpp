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
}