#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool outof(int a, int b, int x, int y) {
    return x >= 0 && y >= 0 && x < a && y < b;
}
int t(int a) {
    if (a == 1) return a;
    else {
        return 0;
    }
} 

int operator<(pair<pair<int,int>,pair<int,int>> a, pair<pair<int,int>,pair<int,int>> b) {
    return (a.first.first > b.first.first);
}
int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<bool>> grid(r, vector<bool>(c, false));
    pair<int,int> start, end;

    for (int i = 0 ; i < r ; i++) {
        for (int j = 0; j < c; j++) {
            char ch;
            cin >> ch;
            if (ch == '#') {
                grid[i][j] = true;
            }
            if (ch == 'C') {
                start = {i,j};
            } 
            if (ch == 'D') {
                grid[i][j] = true;
                end = {i,j};
            }
        }
    }

    
    priority_queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push(pair<pair<int,int>,pair<int,int>>{{0,1}, start});
    vector<vector<vector<bool>>> vis(2, vector<vector<bool>>(r, vector<bool>(c, false)));
    int ans = 0;
    //cout << "here" << endl;
    while (!q.empty()) {
        pair<pair<int,int>,pair<int,int>> p = q.top();
        q.pop();

        int rx, cx;
        int k;
        k = t(p.first.second);
        rx = p.second.first;
        cx = p.second.second;
        //cout << rx << ", " << cx << " | " << p.first.second << endl;
        //cout << k << endl;
        if (rx < 0 || cx < 0 || rx >= r || cx >= c || vis[k][rx][cx]) continue;
        if (rx == end.first && cx == end.second) {
            cout << p.first.first << endl;
            return 0;
        }
        if (grid[rx][cx]) continue;
        //add to queue
        //cout << "here" << endl;
        if (outof(r,c,p.second.first+p.first.second, p.second.second) && grid[p.second.first+p.first.second][p.second.second]) {
            vis[k][p.second.first][p.second.second] = true;
            //cout << "a" << endl;
            q.push(pair<pair<int,int>,pair<int,int>>{p.first, {rx,cx-1}});
            q.push(pair<pair<int,int>,pair<int,int>>{p.first, {rx,cx+1}});

            int newx = rx;
            while (newx >= 0 && newx < r && !grid[newx][cx]) {
                newx -= p.first.second;
            }
            if (cx == end.second && newx == end.first) {
                cout << p.first.first+1 << endl;
                return 0;
            }
            newx += p.first.second;
            //cout << "- " << newx << endl;
            if (newx != 0 && newx != r-1) {
                q.push(pair<pair<int,int>,pair<int,int>>{{p.first.first+1, -p.first.second}, {newx,cx}});
            }
            /*
            while (upx >= 0 && !grid[upx][cx]) upx--;
            while (dwx < r && !grid[dwx][cx]) dwx++;
            if (cx == end.second && (upx == end.first || dwx == end.first)) {
                if (upx == end.first) {
                    cout << p.first.first + (p.first.second == 1) << endl;
                    return 0;
                } else {
                    cout << p.first.first + (p.first.second == -1) << endl;
                    return 0;
                }
            }
            cout << "- " << upx << " " << dwx << endl;
            if (upx != -1) {
                q.push(pair<pair<int,int>,pair<int,int>>{{p.first.first + (p.first.second == 1), -1}, {upx+1,cx}});
            }
            if (dwx != r) {
                q.push(pair<pair<int,int>,pair<int,int>>{{p.first.first + (p.first.second == -1), 1}, {dwx-1,cx}});
            }*/
        } else if (!grid[p.second.first+p.first.second][p.second.second]) {
            //fall
            //cout << "fall" << endl;
            int newx = rx;
            while (newx >= 0 && newx < r && !grid[newx][cx]) {
                newx += p.first.second;
            }
            if (cx == end.second && newx == end.first) {
                cout << p.first.first << endl;
                return 0;
            }
            newx -= p.first.second;
            //cout << "- " << newx << endl;
            if (newx != 0 && newx != r-1) {
                q.push(pair<pair<int,int>,pair<int,int>>{p.first, {newx,cx}});
            }
        }

    }
    cout << -1 << endl;
}