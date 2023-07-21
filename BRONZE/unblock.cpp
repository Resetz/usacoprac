#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef vector<pair<int,int>> diff;
vector<diff> dt;
typedef struct {
    int x1,y1,x2,y2;
} box;

bool intersection(vector<vector<pair<int,int>>> v, diff d) {
    vector<vector<int>> grid(41, vector<int>(41));
    for (int i = 0 ; i < v.size() ; i++) {
        for (int j = 0 ; j < v[i].size() ; j++) {
            int x = v[i][j].first + d[i].first;
            int y = v[i][j].second + d[i].second;
            if (x < 0 || x >= 41 || y < 0 || y >= 41) return false;
            //cout << x << " " << y << endl;
            if (grid[x][y]++) {
                return false;
            }
        }
    }
    return true;
}

bool bounding(vector<box> b, diff d) {
    vector<box> newb = b;
    //cout << "testing diff: ";
    //for (int i = 0 ; i < 3 ; i++) {
    //    cout << d[i].first << " " << d[i].second << " ";
    //}
    //cout << endl;
    for (int i = 0 ; i < 3 ; i++) {
        newb[i].x1 += d[i].first;
        newb[i].x2 += d[i].first;
        newb[i].y1 += d[i].second;
        newb[i].y2 += d[i].second;
        //cout << "(" << newb[i].x1 << ", " << newb[i].y1 << ")" << endl;
        //cout << "(" << newb[i].x2 << ", " << newb[i].y2 << ")" << endl;
    }
    for (int i = 0 ; i < b.size(); i++) {
        for (int j = 0 ; j < b.size() ; j++) {
            if (i == j) continue;
            bool good = false;
            good |= newb[i].x1 > newb[j].x2;
            good |= newb[i].y1 > newb[j].y2;
            good |= newb[i].x2 < newb[j].x1;
            good |= newb[i].y2 < newb[j].y1;
            if (!good) return false;
        }
    }
    return true;
}

int main() {
    dt.resize(8, diff(3));
    for (int i = 0 ; i < 4 ; i++) {
        if (i%2) dt[i][i/2+1].first = 1;
        else dt[i][i/2+1].second = 1;
    }
    for (int i = 4 ; i < 8 ; i++) {
        if (i%2) dt[i][(i-4)/2+1].first = -1;
        else dt[i][(i-4)/2+1].second = -1;
    }
    dt.push_back({{0,0},{1,0},{1,0}});
    dt.push_back({{0,0},{-1,0},{-1,0}});
    dt.push_back({{0,0},{0,1},{0,1}});
    dt.push_back({{0,0},{0,-1},{0,-1}});

    vector<int> n(3);
    cin >> n[0] >> n[1] >> n[2];
    vector<vector<pair<int,int>>> v(3);
    vector<box> b(3);
    for (int i = 0 ; i < 3 ; i++) {
        v[i] = vector<pair<int,int>>(n[i]);
        b[i].x1 = b[i].y1 = 41;
        b[i].x2 = b[i].y2 = 0;
        for (int j = 0 ; j < n[i] ; j++) {
            cin >> v[i][j].first >> v[i][j].second;
            v[i][j].first += 20;
            v[i][j].second += 20;

            b[i].x1 = min(b[i].x1, v[i][j].first);
            b[i].x2 = max(b[i].x2, v[i][j].first);
            b[i].y1 = min(b[i].y1, v[i][j].second);
            b[i].y2 = max(b[i].y2, v[i][j].second);
        }
    }
    
    //cout << bounding(b, {{-3, 0},{0,1},{3, 0}}) << endl;
    set<diff> s;
    queue<pair<int, diff>> q;
    q.push({0, diff(3)});
    int ans = -1;
    while (q.size() > 0) {
        pair<int,diff> d = q.front();
        q.pop();
        //cout << d.first << " " << q.size() << endl;

        //for (int i = 0 ; i < 3 ; i++) {
            //cout << d.second[i].first << " " << d.second[i].second << " ";
        //}
        //cout << endl;

        if (bounding(b, d.second)) {
            ans = d.first;
            break;
        }
        
        for (int i = 0 ; i < dt.size() ; i++) {
            //move

            diff newdiff = diff(3);
            for (int j = 0 ; j < 3; j++) {
                newdiff[j] = {d.second[j].first + dt[i][j].first, d.second[j].second + dt[i][j].second};
            }
            //for (int i = 0 ; i < 3 ; i++) {
            //cout << newdiff[i].first << " " << newdiff[i].second << " ";
            //}
            //cout << "= " << intersection(v, newdiff);
            //cout << endl;
            if (intersection(v, newdiff)) {
                if (s.insert(newdiff).second) q.push({d.first+1, newdiff});
            }
        }
    }
    cout << ans << endl;
}