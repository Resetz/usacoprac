#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>

using namespace std;
        
int n,m;
vector<vector<pair<int,int>>> v;
int go(int k) {
    vector<vector<int>> adj(n);
    vector<int> ind(n, 0);
    for (int i = 0 ; i < k ; i++) {
        for (int j = 0; j < v[i].size() ; j++) {;
            adj[v[i][j].first].push_back(v[i][j].second);
            //cout << v[i][j].first << "->" << v[i][j].second << endl;
            ind[v[i][j].second]++;
        }
    }

    queue<int> q;
    for (int i = 0 ; i < n ; i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    vector<bool> topsorted(n, false);
    while (q.size() > 0) {
        int o = q.front();
        q.pop();
        topsorted[o] = true;
        for (int i = 0 ; i < adj[o].size() ; i++) {
            if (--ind[adj[o][i]] == 0) {
                q.push(adj[o][i]);
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        //cout << "false" << endl;
        if (!topsorted[i]) return false;
    }
    //cout << "true" << endl;
    return true;
    
} 

int main() {
    cin >> n >> m;
    set<pair<int,int>> se;

    for (int i = 0 ; i < m ; i++) {
        int s;
        cin >> s;
        int f = 0;
        cin >> f;
        f--;
        v.push_back(vector<pair<int,int>>());
        for (int j = 1 ; j < s; j++) {
            int t;
            cin >> t;
            t--;
            if (se.insert(pair<int,int>{f,t}).second) v[i].push_back({f,t});
            f = t;
        }
    }
    int high = m;
    int low = 0;
    int ans = -1;
    while ( high >= low ) {
        int mid = low + (high - low)/2;
        //out << mid << endl;
        if (go(mid)) {
            low = mid+1;
            ans = mid;
        } else {
            high = mid-1;
        }
    }
    //cout << ans << endl;
    vector<vector<int>> adj(n);
    vector<int> ind(n, 0);
    for (int i = 0 ; i < ans ; i++) {
        for (int j = 0; j < v[i].size() ; j++) {
            adj[v[i][j].first].push_back(v[i][j].second);
            //cout << v[i][j].first << "->" <<v[i][j].second << endl;
            ind[v[i][j].second]++;
        }
    }

    priority_queue<int> q;
    queue<int> total;
    for (int i = 0 ; i < n ; i++) {
        if (ind[i] == 0) {
            q.push(-i);
        }
    }
    while (q.size() > 0) {
        int o = q.top();
        o = -o;
       // cout << o << endl;
        q.pop();
        total.push(o);

        for (int i = 0 ; i < adj[o].size() ; i++) {
            //cout << adj[o][i] << " (" << o << "->" << ind[adj[o][i]]-1 << ")" << endl;
            if (--ind[adj[o][i]] == 0) {
                q.push(-adj[o][i]);
            }
        }
    }
    while (total.size() > 0) {
        int i = total.front();
        cout << i+1 << " ";
        total.pop();
    }
}