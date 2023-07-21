#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int di[] = {0,0,-1,1};
int dj[] = {1,-1,0,0};

typedef struct {
    int x,y;
    bool type;
} point;

class Compare
{
public:
    bool operator() (pair<int,pair<int,int>> a, pair<int,pair<int,int>> b)
    {
        return a.first > b.first;
    }
};

int main() {
    int n;
    cin >> n;

    vector<point> points;
    vector<point> v;
    vector<int> dx;
    vector<int> dy;
    
    vector<int> tox(300);
    vector<int> toy(300);
    for (int i = 0 ; i < n ; i++) {
    int x,y;
       cin >> x >> y;
       points.push_back(point{x,y, false});
       v.push_back(point{x,y,false});
       v.push_back(point{x+1,y,true});
       v.push_back(point{x-1,y,true});
       v.push_back(point{x,y+1,true});
       v.push_back(point{x,y-1,true});
       dx.push_back(x);
       dx.push_back(x+1);
       dx.push_back(x-1);
       dy.push_back(y);
       dy.push_back(y+1);
       dy.push_back(y-1);
    }
    sort(dx.begin(), dx.end());
    sort(dy.begin(), dy.end());
    dx.resize(unique(dx.begin(), dx.end()) - dx.begin());
    dy.resize(unique(dy.begin(), dy.end()) - dy.begin());
    int nx = 0;
    int ny = 0;
    for (int i = 0; i < v.size(); ++i) {
        int px = v[i].x;
        int py = v[i].y;
        v[i].x = lower_bound(dx.begin(), dx.end(), v[i].x) - dx.begin();
        v[i].y = lower_bound(dy.begin(), dy.end(), v[i].y) - dy.begin();
        tox[v[i].x] = px;
        toy[v[i].y] = py;
        nx = max(nx, v[i].x);
        ny = max(ny, v[i].y);
    }
    nx++;
    ny++;

    for (int i = 0 ; i < n ; i++) {
        points[i].x = lower_bound(dx.begin(), dx.end(), points[i].x) - dx.begin();
        points[i].y = lower_bound(dy.begin(), dy.end(), points[i].y) - dy.begin();
    }

    vector<vector<int>> grid(nx, vector<int>(ny, -1));
    for (int i = 0 ; i < n ; i++) {
        grid[points[i].x][points[i].y] = i;
    }
    //generate grid

    //cout << "here" << endl;
    int cur = 0;
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int f = cur;
        cur++;
        int t = cur;
        if (t == n) t = 0;
        
        //dijkasjdf;lkajsdf
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, Compare> pq;
        pq.push(pair<int,pair<int,int>>{0,{points[f].x, points[f].y}});
        vector<vector<bool>> visited(nx, vector<bool>(ny,false));
        vector<vector<int>> dist(nx, vector<int>(ny,INT_MAX));
        //cout << "here " << f << " " << t << endl;

        while (!pq.empty()) {
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();

            if (visited[p.second.first][p.second.second]) continue;
            //cout << grid[p.second.first][p.second.second] << " " << p.first << " " << p.second.first << " " << p.second.second << " : " << grid[p.second.first][p.second.second] << endl;
            visited[p.second.first][p.second.second] = true;
            if (grid[p.second.first][p.second.second] == t) {
                break;
            }
            for (int j = 0 ; j < 4 ; j++) {
                int newx = p.second.first + di[j];
                int newy = p.second.second + dj[j];
                if (newx < 0 || newx >= nx || newy < 0 || newy >= ny) continue;
                if (visited[newx][newy]) continue;
                int newdist = p.first + abs(dx[newx]-dx[p.second.first]) + abs(dy[newy]-dy[p.second.second]);
                if ((grid[newx][newy] == -1 || grid[newx][newy] == t) && newdist < dist[newx][newy]) {
                    dist[newx][newy] = newdist;
                    pq.push(pair<int,pair<int,int>>{newdist, {newx,newy}});
                }
            }
        }
        ans += dist[points[t].x][points[t].y];
        if (dist[points[t].x][points[t].y] == INT_MAX) {
            cout << -1 << endl;
            return 0;
        }
       // cout << "from " << f << " to " << t << " -> " << dist[points[t].x][points[t].y] << endl;
    }
    cout << ans << endl;
}