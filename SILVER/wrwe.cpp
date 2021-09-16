#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>

#define all(n) n.begin(), n.end()
using namespace std;

int n;
bool visited[100][100];
vector<pair<int,int>> levers[100][100];
bool grid[100][100];
bool flipped[100][100];
vector<pair<int,int>> open;

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

int ans = 0;

bool on(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y];
}
bool vi(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && visited[x][y];
}

bool neighbor(int x, int y) {
    for (int k = 0 ; k < 4 ; k++) {
        if (on(x + di[k], y + dj[k]) && vi(x + di[k], y + dj[k])) {
            return true;
        }
    }
    return false;
}
void dfs(int r, int c) {
    if (vi(r,c)) return;
    visited[r][c] = true;
    for (int i = 0 ; i < levers[r][c].size() ; i++) {
        int x = levers[r][c][i].first;
        int y = levers[r][c][i].second;
        if (!grid[x][y]) {
            grid[x][y] = true;
            if (neighbor(x,y)) dfs(x,y);
        }
    }
    for (int i = 0 ; i < 4; i++) {
        if (on(r+di[i],c+dj[i])) {
            dfs(r+di[i],c+dj[i]);
        }
    }
}

int main() {
    int m;
    cin >> n >> m;

    for (int i = 0 ; i < m ; i++) {
        int xi, yi, xj, yj;
        cin >> xi >> yi >> xj >> yj;
        xi--, yi--, xj--, yj--;
        levers[xi][yi].push_back(make_pair(xj,yj));
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            visited[i][j] = false;
            flipped[i][j] = false;
            grid[i][j] = false;
        }
    }
    grid[0][0] = true;

    //cout << "here" << endl;
    dfs(0, 0);

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (grid[i][j]) ans++;
            //cout << visited[i][j] << " ";
        }
       // cout << endl;
    }
    cout << ans << endl;    
} 