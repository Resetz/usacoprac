#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};

int main() {

    int n; cin >> n;
    vector<pair<int,int>> v;
    int minx, miny, maxx, maxy;
    minx = miny = INT_MAX;
    maxy = maxx = INT_MIN;
    for (int i = 0 ; i < n ; i++) {
        int x,y;
        cin >> x >> y;
        minx = min(minx, x);
        miny = min(miny, y);
        maxx = max(maxx, x);
        maxy = max(maxy, y);
        v.push_back({x,y});
    }
    
    //cout << "here" << endl; 
    int r = maxx-minx+3;
    int c = maxy-miny+3;
    vector<vector<bool>> vis(r, vector<bool>(c, false));
    vector<vector<bool>> mark(r, vector<bool>(c, false));
    for (int i = 0 ; i < n ; i++) {
        v[i].first -= minx-1;
        v[i].second -= miny-1;
        //continueout << v[i].first << " " << v[i].second << endl;
        mark[v[i].first][v[i].second] = true;
        
    }

    int ans = 0;

    queue<pair<int,int>> q;
    for (int i = 0 ; i < r ; i++) {
        q.push({0, i}); 
    }
    while (q.size() > 0) {
        pair<int,int> p = q.front();
        q.pop();

        if (vis[p.first][p.second]) continue;
        vis[p.first][p.second] = true;
        //cout << p.first << " " << p.second << endl;
        bool go[4] = {false, false, false, false};
        bool good = false;
        for (int i = 0 ; i < 4; i++) {
            int newx = p.first + di[i];
            int newy = p.second + dj[i];
            if (newx >= 0 && newx < r && newy >= 0 && newy < c) {
                if (mark[newx][newy]) {
                    ans++;
                    good = true;
                } else {
                    if (vis[newx][newy]) {continue;}
                    go[i] = true;
                }
            }
        }
        if (good) {
            for (int i = 0 ; i < 4; i++) {
                if (go[i]) q.push({p.first + di[i], p.second + dj[i]});
            }
        }
        
    }
    cout << ans << endl;
}