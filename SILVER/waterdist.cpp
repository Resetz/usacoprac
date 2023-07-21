#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> v(n, vector<pair<int,int>>(n));
    vector<vector<bool>> adj(n, vector<bool>(n, false));
    int cur = INT_MAX;
    for (int i = 0 ; i < m ; i++) {
        int f,t,c,fl;
        cin >> f >> t >> c >> fl;
        f--; t--;

        v[f][t] = v[t][f] = {c,fl};
        adj[f][t] = adj[t][f] = true;
        cur = min(cur, fl);
    }

    double best = 0;
    while (true) {
        
        priority_queue<pair<int, int>> pq;
        vector<int> ans(n, -1);
        ans[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();
            p.first = -p.first;
            //cout << p.first << " " << p.second << endl;

            if (ans[p.second] != -1) {
                ans[p.second] = p.first;
                for (int i = 0 ; i < n ; i++) {
                    if (adj[p.second][i] && v[p.second][i].second >= cur) {
                        
                        if (ans[i] == -1 || p.first + v[p.second][i].first < ans[i]) {
                            ans[i] = p.first+v[p.second][i].first;
                            pq.push({-(p.first+v[p.second][i].first), i});
                        }

                    }
                }
            } else {
                continue;
            }
        }
        if (ans[n-1] == -1) break;
        best = max(best, ((double) cur/ans[n-1]));
        cur++;
    }

    cout << (int)(best*1000000) << endl;

}