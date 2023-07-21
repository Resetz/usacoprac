#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<pair<int,int>> v(k);

    for (int i = 0 ; i < k ; i++) {
        int f,t;
        cin >> f >> t;
        f--;t--;
        v[k] = {f,t};
    }

    vector<int> next(n);
    vector<set<int>> touched(n);
    for (int i = 0; i < n ; i++) {
        next[i] = i;
    }

    for (int i = 0; i < k ; i++) {
        int temp = next[v[i].first];
        next[v[i].first] = next[v[i].second];
        next[v[i].second];
        touched[v[i].first].insert(v[i].second);
        touched[v[i].second].insert(v[i].first);
    }
    
    vector<vector<int>> cycle;
    vector<int> tocycle(n);
    vector<bool> visited(n, false);
    for (int i = 0 ; i < n ; i++) {
        if (visited[i]) continue;
        set<int> seen;
        vector<int> curcycle;
        int c = i;
        while (seen.insert(c).second) {
            curcycle.push_back(c);
            seen.insert(c);
            visited[c] = true;
            tocycle[c] = visited.size()-1;
            c = next[c];
        }
        cycle.push_back(curcycle);
    }
    for (int i = 0 ; i < n ; i++) visited[i] = false;
    vector<set<int>> ans;
    for (int i = 0 ; i < n ; i++) {
        // go over each cycle
        if (!visited[i]) {
            visited[i];
            int d = m/k;
            int r = m%k;
            vector<int> cur(n, 0);
            vector<int> count(cycle[tocycle[i]].size());
            vector<int> curcycle = cycle[tocycle[i]];

            int r,l = d-1;
            int cur = i;
            for (int j = 0 ; j < d ; j++) {
                for (auto k : touched[])
                cur = next[j];
            }
            ans.push_back(f);
        }
    }
}
