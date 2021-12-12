#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<bool> vis(n);
    vector<pair<int,int>> adj;
    for (int i = 0; i < k; i++) {
        int f, t;
        cin >> f >> t;
        f--; t--;
        adj.push_back({f,t});
    }

    vector<unordered_set<int>> dp(n, unordered_set<int>());

    vector<int> cur(n);
    for (int i = 0; i < n ; i++) {
        cur[i] = i;
        dp[i].insert(i);
    }
    for (int i = 0; i< k; i++) {
        int f, t;
        f = adj[i].first;
        t = adj[i].second;

        int temp = cur[t];
        cur[t] = cur[f];
        cur[f] = temp;

        dp[cur[f]].insert(t);
        dp[cur[t]].insert(f);
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[cur[i]] = i;
    }

    vector<bool> v(n, false);
    vector<int> ans(n);
    for (int i = 0; i < n ; i ++) {
        //cout << p[i] << " ";
        if (v[i]) continue;
        unordered_set<int> s;
        int current = i;
        vector<int> cows;
        while (!v[current]) {
            cows.push_back(current);
            s.insert(dp[current].begin(), dp[current].end());
            v[current] = true;
            current = p[current];
        }
        for (int i = 0 ; i < cows.size(); i++) {
            ans[cows[i]] = s.size();
        }
    }
    //cout << endl;
    for (int i = 0 ; i < n ; i++) {
        cout << ans[i] << endl;
    }


    /*
    for (int i = 0;  i< n ; i++) {
        fill(vis.begin(), vis.end(), 0);
        int time = 0;
        int current = i;
        int endtime = -1;
        set<int> ans;
        while (true) {
            if (ans.size() >= n) {
                break;
            } 
            ans.insert(current);
            if (adj[current].size() == 0) {
                break;
            }
            if (adj[current][adj[current].size()-1].second < time) {
                time = 0;
            }
            pair<int,int> ind = (*lower_bound(adj[current].begin(), adj[current].end(), time, 
                [](pair<int,int> p, int i) -> int {
                    return p.second < i;
                }));
            if (endtime == -1) {
                endtime = ind.second;
            } else {
                if (current == i && ind.second == endtime) {
                    break;
                }
            }
            time = ind.second+1;
            current = ind.first;
        }
        //cout << "HERE" << endl;
        cout << ans.size() << endl;
    }*/
}