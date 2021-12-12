#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v;
vector<int> p;

vector<vector<int>> adj;

int ans = 0;

int current = 0;
bool vis[200] = {false};

void dfs(int k) {
    current++;
    vis[k] = true;
    for (int i = 0 ; i < adj[k].size() ; i++) {
        if (!vis[adj[k][i]]) {
            dfs(adj[k][i]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    for (int i = 0 ; i < n ; i++) {
        int x, y, power;
        cin >> x >> y >> power;
        v.push_back({x,y});
        p.push_back(power);
    }

    for (int i = 0;  i < n ; i++) {
        int power= p[i]*p[i];
        for (int j = 0 ; j < n ; j++) {
            if (i == j) continue;
            int dx = abs(v[j].first - v[i].first);
            int dy = abs(v[j].second - v[i].second);

            if (dx*dx + dy*dy <= power) {
                adj[i].push_back(j);
                //cout << j << " ";
            }
        }
        //cout << endl;
    }

    for (int i = 0 ; i < n ; i++) {
        
        current = 0;
        for (int j = 0; j < n ; j++) {
            vis[j] = false;
        }
        dfs(i);
        //cout << i << " " << current << endl;
        ans = max(current, ans);
    }
    cout << ans;

}