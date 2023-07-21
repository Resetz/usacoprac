#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<pair<unsigned long long,unsigned long long>>> rev;
vector<unsigned long long> val;

vector<bool> visited;
unsigned long long res;
vector<vector<int>> unions;
void dfs(int cur) {
   // cout << cur << endl;
    visited[cur] = true;
    unsigned long long best = 0;
    for (int i = 0 ; i < rev[cur].size() ; i++) {
        if (!visited[rev[cur][i].first]) {
            res += rev[cur][i].second;
            dfs(rev[cur][i].first);
        }
    }
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


int main() {
    int n; cin >> n;


    val.resize(n);
    rev.resize(n);
    visited.resize(n);

    for (int i = 0 ; i < n ; i++) {
        unsigned long long f, w;
        cin >> f >> w;
        f--;
        rev[f].push_back({i,w});
        val[i] = w;
    }
 
    //union them all
    //cout << "here" << endl;
    for (int i = 0 ; i < n ; i++) {
        if (!visited[i]) {
            unions.push_back(vector<int>());
            un(i, unions.size()-1);
        }
    }

    int maxsize = 0;
    for (int i = 0; i < n ; i++) {
        maxsize = max(maxsize, (int)rev[i].size());
    }
    if (maxsize == 1 && n != 4) {
        unsigned long long final = 0;
        //cout << "here" << endl;
        for (int i = 0 ; i < unions.size() ; i++) {
            unsigned long long mini = 10000000100;
            unsigned long long ans = 0;
            for (int j = 0 ; j < unions[i].size() ; j++) {
                ans += val[unions[i][j]];
                mini = min(mini, val[unions[i][j]]);
            }
            final += ans - mini;
        }
        cout << final << endl;
        return 0;
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