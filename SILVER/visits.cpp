#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<pair<unsigned long long,unsigned long long>>> rev;
vector<pair<unsigned long long, unsigned long long>> go;

vector<bool> visited;
vector<bool> visited2;
unsigned long long res;
unsigned long long res2;



vector<vector<int>> unions;
vector<int> roots;

unsigned long long dfs(int cur) {
   // cout << cur << endl;
    visited[cur] = true;
    unsigned long long best = 0;
    for (int i = 0 ; i < rev[cur].size() ; i++) {
        if (!visited[rev[cur][i].first]) {
            res += rev[cur][i].second;
            dfs(rev[cur][i].first);
        }
    }
    return res;
}

void un(int cur, int ind) {
    visited[cur] = true;
    unions[ind].push_back(cur);
    for (int i = 0 ; i < rev[cur].size() ; i++) {
        if (!visited[rev[cur][i].first]) {
            un(rev[cur][i].first, ind);
        }
    }
}

int findcycle(int cur) {
    visited[cur] = true;
    for (int i = 0 ; i < rev[cur].size() ; i++) {
        if (!visited[rev[cur][i].first]) {
            int res = findcycle(rev[cur][i].first);
            if (res != -1) {
                return res;
            }
        } else {
            return cur;
        }
    }
    return -1;
}

int findbest(int cur) {
    visited2[cur] = true;
    unsigned long long curval = 0;
    for (int i = 0 ; i < rev[cur].size() ; i++) {
        res = 0;
        dfs(cur);
    }
    res2 = max(res2, );
    if (visited2[go[cur].first]) return;
}

int main() {
    int n; cin >> n;

    rev.resize(n);
    visited.resize(n);
    go.resize(n);

    for (int i = 0 ; i < n ; i++) {
        unsigned long long f, w;
        cin >> f >> w;
        f--;
        rev[f].push_back({i,w});
        go[i] = {f,w};
    }


    for (int i = 0 ; i < n ; i++) {
        if (!visited[i]) {
            unions.push_back(vector<int>());
            un(i, unions.size()-1);
        }
    }
   // cout << "here" << endl;

    roots.resize(unions.size());
    for (int i = 0 ; i < n ; i++) {

    }
    vector<unsigned long long> ans(unions.size(), 0);
    for (int i = 0 ; i < unions.size() ; i++) {
        //cout << "- " << endl;
        for (int j = 0 ; j < unions[i].size() ; j ++) {
            //cout << j << " ";
            fill(visited.begin(), visited.end(), false);
            //cout << "dfsing over " << j << endl;
            dfs(unions[i][j]);
            //cout << res << " " << endl;
            
            ans[i] = max(ans[i], res);
            res = 0;
        }
    }
    unsigned long long final = 0;
    for (int i = 0 ; i < ans.size(); i++) {
        final += ans[i];
    }
    cout << final << endl;

}