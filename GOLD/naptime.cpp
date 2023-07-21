#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


int main() {
    int t,f,b;
    cin >> t >> f >> b;
    vector<bool> spots(t, false);

    for (int i = 0 ; i < f ; i++) {
        int num;
        cin >> num;
        spots[num-1] = true;
    }


    vector<vector<pair<int,int>>> adj(t, vector<pair<int,int>>());
    for (int i = 0 ; i < b ; i++) {
        int f,t,l;
        cin >> f >> t >> l;
        f--;t--;
        adj[f].push_back({t,l});
        adj[t].push_back({f,l});
    }
    
    int best = INT_MAX;
    int ind = 0;
    for (int it = 0 ; it < t; it++) {
        //root at i;
        priority_queue<pair<int,int>> pq;
        pq.push({0, it});
        vector<int> v(t, false);

        int cur = 0;
        while (!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();

            if (v[p.second]) continue;
            p.first = -p.first;
            v[p.second] = true;

            //cout << p.first << " " << p.second << endl;
            if (spots[p.second]) {
                //cout << "- " << p.second+1<< " " << p.first << endl;
                cur += p.first;
            }
            for (int i = 0 ; i < adj[p.second].size() ; i++) {
                if (v[adj[p.second][i].first]) continue;
                pq.push({-(p.first + adj[p.second][i].second), adj[p.second][i].first});
            }
        }
        //cout << it+1 << " " << cur << endl;
        if (best > cur) {
            best = cur;
            ind = it;
        }
    }
    cout << ind+1 << endl;
}