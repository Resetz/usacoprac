#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
int grid[1000][1000];
int xpref[1001][1001];
int ypref[1001][1001];

int get(int x, int y) {
    int ret = 0;
    m--; 
    ret += ypref[x+m][y] - ypref[x-1][y];
    ret += ypref[x+m][y+m] - ypref[x-1][y+m];
    ret += xpref[x][y+m] - xpref[x][y-1];
    ret += xpref[x+m][y+m] - xpref[x+m][y-1];
    x--;
    y--;
    ret -= grid[x][y];
    ret -= grid[x+m][y+m];
    ret -= grid[x+m][y];
    ret -= grid[x][y+m];
    m++;
    return ret;
}

bool overlap(int x, int y, int x1, int y1) {
    return abs(x-x1) < m && abs(y-y1) < m;
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> grid[i][j];
            xpref[i+1][j+1] = xpref[i+1][j] + grid[i][j];
            ypref[i+1][j+1] = ypref[i][j+1] + grid[i][j];
        }
    }


    vector<pair<int,pair<int,int>>> v;

    int ans = INT_MAX;

    for (int i = 0 ; i < n-m+1; i++) {
        for (int j = 0 ; j < n-m+1; j++) {
            int val = get(i+1, j+1);
            if (v.size() == 0 ) {
                v.push_back({val,{i, j}});
                continue;
            }

    
            int current = v.size()-1;
            while (current > 0 && overlap(i,j,v[current].second.first,v[current].second.second)) {
                current--;
            }
            if ( !overlap(i,j,v[current].second.first,v[current].second.second) ) {
                ans = min(val + v[current].first, ans);
            }

            if (val < v[v.size()-1].first) {
                v.push_back({val,{i, j}});
            }
        } 
    }
    cout << ans << endl;
}