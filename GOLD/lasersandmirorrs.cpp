#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

int main() {
    int n, ax,ay,bx,by;
    cin >> n >> ax >> ay >> bx >> by;

    map<int,vector<pair<int,int>>> ady;
    map<int,vector<pair<int,int>>> adx;
    vector<pair<int,int>> v;
    for (int i = 0 ; i < n ; i++) {
        int x,y;
        cin >> x >> y;
        if (adx.count(x) == 0) {
            adx[x] = vector<pair<int,int>>();
        }
        adx[x].push_back({y,i});
        if (adx.count(y) == 0) {
            adx[y] = vector<pair<int,int>>();
        }
        ady[y].push_back({x,i});
        v.push_back({x,y});
    }
    adx[ax].push_back({ay,n});
    ady[ay].push_back({ax,n});
    v.push_back({ax,ay});

    adx[bx].push_back({by,n+1});
    ady[by].push_back({bx,n+1});
    v.push_back({bx,by});

    priority_queue<pair<int,int>> pq;
    set<int> vis;
    pq.push({0, n});
    while (!pq.empty()) {
        pair<int,int> p = pq.top();
        pq.pop();

        if (p.second == n+1) {
            cout << -p.first -1 << endl;
            return 0;
        }
        p.first = -p.first;
       // cout << p.first << " " << p.second << endl;
        
        pair<int,int> loc = v[p.second];

        for (int i = 0 ; i < ady[loc.second].size() ; i++) {
            if (vis.insert(ady[loc.second][i].second).second) pq.push(pair<int,int>{-(p.first + 1), ady[loc.second][i].second});
        }
        for (int i = 0 ; i < adx[loc.first].size() ; i++) {
            if (vis.insert(adx[loc.first][i].second).second) pq.push(pair<int,int>{-(p.first + 1), adx[loc.first][i].second});
        }
    }
    cout << -1 << endl;
}