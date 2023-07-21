#pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

vector<vector<int>> adj;
int n;

vector<int> vis;
int r;


void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}


int dfs(int k) {
    int ans = 0;
    vis[k] = true;
    //cout << "dfs " << k << endl;

    multiset<int> ms;
    //bool go = false;

    for (int i = 0 ; i < adj[k].size() ; i++) {
        if (vis[adj[k][i]]) continue;
        int l;
        //go = true;
        l = dfs(adj[k][i]);
        if (l == r) {
            continue;
        }
        if (l == -1) return -1;
        if (ms.find(r-l) != ms.end()) {
            //cout << l << " remove " << r-l << endl;
            ms.erase(ms.find(r-l));
            continue;
        }
        //cout << l << " add " << endl;
        ms.insert(l);
    }

    //if (!go) return 1;
    if (ms.size() > 1) {
        ans = -2;
    } else if (ms.size() == 1) {
        ans = *ms.begin();
    } else {
        ans = 0;
    }
    ans = ans % r;
    //cout << "dfs(" << k << ") " << r << " = " << ans+1 << endl;
    return ans+1;
}

int go(int k) {
    if ((n-1) % k != 0) return false;
    else {
        for (int i = 0 ; i < n ; i++) {
            vis[i] = false;
        }
        r = k;
        int res = dfs(1);
        //cout << k << " " << res << endl;
        return res == 1;
    }
}

int main() {
    setIO("deleg"); 
    cin >> n;

    adj.resize(n, vector<int>());
    vis.resize(n, false);

    for (int i = 1 ; i < n ; i++) {
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
    

    for (int i = 1 ; i < n ; i++) {
        cout << (go(i) ? "1" : "0");
        
    }
    cout << endl;

}