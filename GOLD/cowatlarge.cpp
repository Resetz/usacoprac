#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,k;
vector<vector<int>> adj;
vector<int> height;
vector<bool> visited;

void bfs(int k, bool up, int original) {
    if (visited[k]) return;
    visited[k] = true;
   // cout << k+1 << " visited" << endl;
    if (up) {
        if (height[k] == (original+1)/2) {
        //     cout << original << " stops " << height[k] << " " << k << endl;
            //downard
            for (int i = 0 ; i < adj[k].size() ; i++) {
                if (height[adj[k][i]] > height[k]) {
                    //cout << k << " down " << adj[k][i] << endl;
                    bfs(adj[k][i], false, original);
                }
            }
        } else {
            for (int i = 0 ; i < adj[k].size() ; i++) {
                if (height[adj[k][i]] < height[k]) {
                    //cout << k << " -> " << adj[k][i] << endl;
                    bfs(adj[k][i], true, original);
                } else {
                    bfs(adj[k][i], false, original);
                }
            }
        }
    } else {
        for (int i = 0 ; i < adj[k].size() ; i++) {
            if (height[adj[k][i]] > height[k]) {
                bfs(adj[k][i], false, original);
            }
        }
    }
}

int main() {
    freopen("atlarge.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("atlarge.out", "w", stdout);
    cin >> n >> k;
    k--;
    adj.resize(n);
    height.resize(n, -1);
    visited.resize(n, false);

    for (int i = 0 ; i < n-1 ; i++) {
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    } 

    queue<pair<int,int>> q;
    q.push({k,0});
    height[k] = 0;

    vector<pair<int,int>> leaf;

    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for (int i = 0 ; i < adj[p.first].size(); i++) {
            if (height[adj[p.first][i]] == -1) {
                height[adj[p.first][i]] = p.second+1;
                q.push({adj[p.first][i], p.second+1});
            }
        }
        if (p.first != k && adj[p.first].size() == 1) {
            leaf.push_back({p.second, p.first});
        }
    }

    sort(leaf.begin(), leaf.end());

    int placed = 0;
    for (int i = 0 ; i < leaf.size() ; i++) {
        //cout << "leaf " << leaf[i].first << " " << leaf[i].second << endl;
        if (visited[leaf[i].second]) continue;
        placed++;
        bfs(leaf[i].second, true, leaf[i].first);
    }
    cout << placed << endl;




}
/* 

9 9
1 2
1 3
3 4
3 5
4 6
5 7
7 8
9 1

*/