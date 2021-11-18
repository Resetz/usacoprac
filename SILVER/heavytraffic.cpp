#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
#include <vector>

using namespace std;
int n,m;

int adj[3000][3000];

int visited[3000] = {-1};
bool seen[3000] = {false};
set<int> counted;
vector<int> p;

vector<int> cycle;

bool found = false;
int pre = -1;

void dfs(int k, int start) {
    if (!seen[k] && (visited[k] == start || visited[k] == -1)) { 
        //cout << k << " " << start << " -> ";
        //cout.flush();
        visited[k] = start;
        seen[k] = true;
        bool found_current = false;
        int lpre = pre;
        for (int i = 0; i < n; i++) {
            if (i == lpre) continue;
            if (adj[k][i] == 1 && visited[i] == start) {
                found = true;
                //cout << "cycle: " << k << " " << start << endl;
                found_current = true;
            } else {
                if (adj[k][i] == 1 && (visited[i] == start || visited[i] == -1)) {
                    //cout << i << endl;
                    found = false;
                    pre = k;
                    dfs(i, start);
                    if (found) found_current = true;
                }
            }
        }
        if (!found_current) {
            visited[k] = -1;
            return;
        } else {
            found = true;
            return;
        }
    }
}

void noncycle(int k, int start) {
    seen[k] = true;
    visited[k] = start;

    for (int i = 0 ; i < n ; i++) {
        if (!seen[k] && adj[k][i] == 1 && visited[i] == -1) {
            noncycle(i, start);
        }
    } 
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        adj[f][t] = 1;
        adj[t][f] = 1;
        
    }

    for (int i = 0 ; i < n ; i++) {
        visited[i] = -1;
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            seen[j] = false;
        }
        found = false;
        if (visited[i] == -1) {
            pre = -1;
            dfs(i, i);
            //cout << endl;
        }
    }
    //count non-cycles;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            seen[j] = false;
        }
        if (visited[i] == -1) {
            noncycle(i, -i-2);
        }
    }

    vector<pair<int,int>> ans;
    //cout << endl;
    for (int i = 0 ; i < n ; i++) {
        //cout << visited[i] << " ";
        for (int j = i+1 ; j < n ; j++) {
            if (adj[i][j] && visited[i] != visited[j] && counted.insert(visited[j]).second) {
                ans.push_back({i,j});
            }
        }
    }
    //cout << endl;
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0 ; i < ans.size() ; i++) {
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    }
}