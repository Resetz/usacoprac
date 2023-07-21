#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
vector<vector<bool>> adj;
vector<vector<bool>> ans;
vector<vector<int>> v;
int n;
vector<bool> visited;
void dfs(int cur, int source) {
    ans[source][cur] = true;
    //cout << source << " : " << cur << endl;
    for (int i = 0 ; i < v[cur].size(); i++) {
        if (!ans[source][v[cur][i]]) {
            dfs(v[cur][i], source);
        }
    } 
}

int main() {
    cin >> n;
    v.resize(n, vector<int>());
    for (int i = 0 ; i < n ;i++) {
        int k = 0;
        bool done = false;
        for (int j = 0 ; j < n ; j++) {
            cin >> k;
            k--;
            if (!done) v[i].push_back(k);
            if (i == k) {
                done = true;
            }
        }
    }
    
    adj.resize(n, vector<bool>(n, false));
    ans.resize(n, vector<bool>(n, false));
    visited.resize(n);

    for (int i = 0 ; i < n ; i++) {
        //cout << "dfs from " << i << " " << v[i][v[i].size()-1] << endl;
        dfs(i, i);
        for (int j = 0 ; j < n ; j++) {
            visited[j] = false;
        }
    }

    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < v[i].size() ; j++) {
            //cout << "check " << i << " " << v[i][j] << endl;
            if (ans[v[i][j]][i]) {
                cout << v[i][j]+1 << endl;
                break;
            }
        }
    }


    
}