#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

vector<vector<int>> adj;

int game[1000] = {-1};

bool visited[1000]= {false};

int n;
int m;

int invalida;
int invalidb;

bool simulate() {
    bool good = true;
    for (int i = 0 ; i < m ; i++) {
        if(!visited[i]) {
            queue<pair<int,int>> q;
            q.push({i,0});
            while (!q.empty()) {
                pair<int,int> num = q.front();
                q.pop();
            
                if (visited[num.first] && game[num.first] != num.second) {
                    good = false;
                    break;
                }
                if (visited[num.first]) {
                    continue;
                }
                game[num.first] = num.second;
                visited[num.first] = true;
                for (int j = 0 ; j < adj[num.first].size() ; j++) {
                    if (num.first == invalida && adj[num.first][j] == invalidb || num.first == invalidb && adj[num.first][j] == invalida) {
                        continue;
                    }
                
                    if (!visited[adj[num.first][j]]) q.push({adj[num.first][j], 1-num.second});
                }
            }
            if (!good) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;

    adj.resize(m);
    vector<pair<int,int>> bonds;
    for (int i = 0 ; i < n ; i++) {
        int f, t;
        cin >>f >> t;
        f--;
        t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
        bonds.push_back({f, t});
    }
    
    for (int i = 0 ; i < m ; i++) {
        game[i] = -1;
    } 

    bool good = true;
    for (int i = 0 ; i < m ; i++) {
        if(!visited[i]) {
            queue<pair<int,int>> q;
            q.push({i,0});
            while (!q.empty()) {
                pair<int,int> num = q.front();
                q.pop();
                if (game[num.first] != -1 && game[num.first] != num.second) {
                    good = false;
                    break;
                }
                game[num.first] = num.second;
                if (visited[num.first]) continue;
                visited[num.first] = true;
                for (int j = 0 ; j < adj[num.first].size() ; j++) {
                    if (!visited[adj[num.first][j]]) q.push({adj[num.first][j], 1-num.second});
                }
            }
        }
    }
    if (good) { 
        cout << "MOO" << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        invalida = bonds[i].first;
        invalidb = bonds[i].second;
        for (int j = 0 ; j < m ; j++) {
            visited[j] = false;
        }
        for (int j = 0 ; j < m ; j++) {
            game[j] = -1;
        }

        if (simulate()) ans++;
    }
    if (ans != 0) {
        cout << ans << endl;
    } else {
        cout << "MOO MOO" << endl;
    }


}