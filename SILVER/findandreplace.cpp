#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int ton(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A'+26;
    }
    return 0;
}

void solve() {
    int n;
    string a,b;
    cin >> a >> b;

    //sort(a.begin(),a.end());
    //sort(b.begin(),b.end());
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    n = a.size();
    vector<int> tmp(56, -1);
    vector<int> to(56, -1);
    vector<vector<int>> rev(56, vector<int>());
    vector<int> indeg(56, 0);
    vector<int> odeg(56, 0);
    set<int> s;
    for (int i = 0 ; i < n ; i++) {
        s.insert(b[i]);
        if (tmp[ton(a[i])] != -1 && tmp[ton(a[i])] != ton(b[i])) {
            cout << -1 << endl;
            return;
        } else {
            tmp[ton(a[i])] = ton(b[i]);
            if (ton(a[i]) == ton(b[i])) continue;
            
            to[ton(a[i])] = ton(b[i]);
            rev[ton(b[i])].push_back(ton(a[i]));

            indeg[ton(b[i])]++; 
            odeg[ton(a[i])]++; 
        }
    }
    if (s.size() == 52) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    //look for paths
    vector<int> vis(56);
    for (int i = 0 ; i < 56 ; i++) {
        if (odeg[i] == 0) {
            //traverse backward
            queue<int> q;
            q.push(i);
            int pathlen = 0;
            while (q.size() > 0) {
                int k = q.front();
                q.pop();
                vis[k] = true;
                if (to[k] != -1 && !vis[to[k]]) {
                    q.push(to[k]);
                    vis[to[k]] = true;
                    pathlen++;
                }
                for (int j = 0 ; j < rev[k].size() ; j++) {
                    if (!vis[rev[k][j]]) {
                        q.push(rev[k][j]);
                        vis[rev[k][j]] = true;
                        pathlen++;
                    }
                }
            }
            ans += pathlen;
        }

    }
    //the only remaining ones should be cycles or paths leading up to cycles.
    for (int i = 0 ; i < 56 ; i++) {
        if (!vis[i]) {
            //do a floodfill
            queue<int> q;
            q.push(i);
            int edges = 1;
            bool standalone = false;
            while (q.size() > 0) {
                int k = q.front();
                q.pop();
                vis[k] = true;
                if (to[k] != -1 && !vis[to[k]]) {
                    q.push(to[k]);
                    vis[to[k]] = true;
                    edges++;
                }
                if (rev[k].size() == 0) {
                    standalone = true;
                }
                for (int j = 0 ; j < rev[k].size() ; j++) {
                    if (!vis[rev[k][j]]) {
                        q.push(rev[k][j]);
                        vis[rev[k][j]] = true;
                        edges++;
                    }
                }
            }
            //cout << "v " << i << " " << edges << endl;
            ans += edges + (!standalone);
        }
    }
    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}