#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,c;
vector<vector<pair<int,int>>> v;
vector<int> inc;
vector<int> ans;
void dfs(int k, int t) {
    ans[k] = max(t, ans[k]);
   // cout << " - " << k  << " " << t << endl;
    for (int i = 0 ; i < v[k].size() ; i++) {
        dfs(v[k][i].first, t+v[k][i].second);
    }
    
}

int main() {
    cin >> n >> m >> c;
    vector<int> start(n, 0);


    v.resize(n, vector<pair<int,int>>());
    inc.resize(n, 0);
    ans.resize(n, 0);
    for (int i = 0 ; i < n ; i++) {
        cin >> ans[i];
        //cout << inc[i] << endl;
    }


    for (int i = 0 ; i < c ; i++) {
        int f,t,a;
        cin >> f >> t >> a;
        f--;t--;
        v[f].push_back({t,a});
        inc[t]++;
    }

    queue<int> q;
    for (int i = 0 ; i < n ; i++) {
        if (inc[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int k = q.front(); q.pop();

        for (int i = 0 ; i < v[k].size() ; i++) {
            ans[v[k][i].first] = max(ans[v[k][i].first], ans[k] + v[k][i].second);
            inc[v[k][i].first]--;
            if (inc[v[k][i].first] == 0) q.push(v[k][i].first);
        }
    }
    for (int i = 0 ; i < n ; i++) {
        cout << ans[i] << endl;
    }
    
}