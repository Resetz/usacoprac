#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<pair<int,bool>>> adj;
    
int n;
int m;

int visited[100000] = {false};
int game[100000] = {0};
int main() {
    cin >> n >> m;
    adj.resize(n);
    
    for (int i = 0 ; i < m ; i++) {
        int f, t;
        char d;
        cin >> d >> f >> t;
        f--;
        t--;
        adj[f].push_back({t, d == 'S'});
        adj[t].push_back({f, d == 'S'});
    }
    for (int i = 0 ; i < n ; i++) {
        game[i] = -1;
    }

    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        if (visited[i]) continue;

        queue<pair<int,int>> q;
        game[i] = 0;
        q.push({i, 0});
        bool good = true;
        while (!q.empty()) {
            pair<int,int> num = q.front();
            q.pop();
            if (visited[num.first]) {
                continue;
            }
            visited[num.first] = true;
            
            
            for (int j = 0 ; j < adj[num.first].size(); j++) {
                int go = adj[num.first][j].first;
                bool same = adj[num.first][j].second;
                if (visited[go]) {
                    if (same && game[num.first] != game[go]) {
                        good = false;
                    } else if (!same && game[num.first] == game[go]) {
                        good = false;
                    }
                } else {
                    if (same) {
                        game[go] = game[num.first]; 
                    } else {
                        game[go] = 1 - game[num.first];
                    }
                    q.push({go, game[go]});
                }
            }
        }
        if (good) {
            ans++;
        }
    }
    if (ans > 0) {
        cout << 1;
        for (int i = 0 ; i < ans; i++) {
            cout << 0; 
        }
        cout << endl;
    } else {
        cout << 0 << endl;
    }
}