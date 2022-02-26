#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> curorder;
vector<pair<int,int>> cows;
vector<bool> visited;
vector<bool> visited2;
vector<vector<pair<int,pair<int,int>>>> dir;
int n,m;

vector<int> extra;

vector<int> found;

set<int> used;

vector<bool> ign;

vector<bool> good;

vector<int> ans;

int go = -1;
int fa = -1;

void dfs(int cereal, int cur) {
    visited[cereal] = true;
    if (cur != -1 && go == -1) go = cur;

    for (pair<int,pair<int,int>> p : dir[cereal]) {
        if (visited[p.first]) {
            if (fa == -1 && p.second.first != cur) {
                fa = p.second.first;
                ans.push_back(fa);
                good[fa] = true;
            }
        } else {
            if (used.insert(p.second.first).second) dfs(p.first, p.second.first);
        }
    }
}

void dfs2(int cereal) {
    visited2[cereal] = true;
    for (pair<int, pair<int,int>> p : dir[cereal]) {
        if (!visited2[p.first] && !ign[p.second.first]) {
            good[p.second.first] = true;
            ans.push_back(p.second.first);
            dfs2(p.first);
        }
    }
}

int main() {
    cin >> n >> m;

    cows.resize(n);
    dir.resize(m, vector<pair<int,pair<int,int>>>());
    visited.resize(n);
    visited2.resize(n);
    good.resize(n);
    ign.resize(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> cows[i].first >> cows[i].second;
        cows[i].first--;
        cows[i].second--;
        dir[cows[i].first].push_back({cows[i].second, {i, 1}});
        dir[cows[i].second].push_back({cows[i].first, {i, 0}});
    }

    for (int i = 0 ; i < m ; i++) {
        if (!visited[i]) {
            go = -1;
            fa = -1;
            dfs(i, -1);

            found.clear();
            if (fa != -1) {
                ign[fa] = true;
                dfs2(cows[fa].first);
            } else {
                dfs2(cows[go].first);
            }
        }
    }
    
    int hungry = 0;
    for (int i = 0 ; i < n ; i++) {
        if (!good[i]) {
            hungry++;
            ans.push_back(i);
        }
    }

    cout << hungry << endl;
    for (int i = 0 ; i < n ; i++) {
        cout << ans[i]+1 << endl;
    }
}