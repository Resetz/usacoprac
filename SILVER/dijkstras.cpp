#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

#define EDGES 5

int main() {
    vector<pair<int,int>> v[EDGES];
    v[0].push_back(make_pair(1, 2));
    v[0].push_back(make_pair(2, 7));
    
    v[1].push_back(make_pair(3, 2));
    
    v[3].push_back(make_pair(4, 10));

    v[2].push_back(make_pair(4, 1));

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 0));

    int results[EDGES];
    for (int i = 0 ; i < EDGES ; i++) {
        results[i] = INT_MAX;
    }

    while (!pq.empty()) {
        
        pair<int, int> p = pq.top(); pq.pop();
        results[p.second] = p.first;
        for (int i = 0 ; i < v[p.second].size() ; i++) {
            if (results[v[p.second][i].first] == INT_MAX) {
                pq.push(make_pair(p.first + v[p.second][i].second, v[p.second][i].first));
            }
        }
    }
    for (int i = 0 ; i < EDGES ; i++) {
        cout << results[i] << endl;
    }

}