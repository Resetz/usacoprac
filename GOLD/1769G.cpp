#include <iostream>
#include <vector>
#include <queue>
#include <set>
 
using namespace std;
 
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
 
    vector<vector<pair<int,int> > > v(n, vector<pair<int,int> >());
    for (int i = 0 ; i < n-1 ; i++) {
        int f,t,w;
        cin >> f >> t >> w;
        f--; t--;
        v[f].push_back(pair<int,int>(t, w));
        v[t].push_back(pair<int,int>(f, w));
    }
    
    a--; b--;
    queue<pair<int,int> > q;
    set<int> s;
    set<int> vis;
    vis.insert(a);
    q.push(pair<int,int>(a, 0));
    while (q.size() > 0) {
        pair<int,int> p = q.front();
        q.pop();
 
        if (p.first != b) s.insert(p.second);
        if (p.first == b) {
            continue;
        }
        for (int i = 0 ; i < v[p.first].size() ; i++) {
            pair<int,int> e = v[p.first][i];
            if (vis.insert(e.first).second) q.push(pair<int,int>(e.first, p.second ^ e.second));
        }
    }
 
    q.push(pair<int,int>(b, 0));
    vis.clear();
    //vis.insert(b);
    while (q.size() > 0) {
        pair<int,int> p = q.front();
        q.pop();
 
        
        if (p.first != b && p.first != a && s.find(p.second) != s.end()) {
            cout << "YES" << endl;
            return;
        }
 
        for (int i = 0 ; i < v[p.first].size() ; i++) {
            pair<int,int> e = v[p.first][i];
            if (vis.insert(e.first).second) q.push(pair<int,int>(e.first, p.second ^ e.second));
        }
    }
 
    cout << "NO" << endl;
}
 
int main() {
    int n; cin >> n;
    while (n--) solve();
}