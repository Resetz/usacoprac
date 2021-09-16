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

void dfs(int r, int c) {
    //cout << (visited[r][c]) << (r < 0) << (c < 0) << (r >= n) << (c >= n) << endl; 
    if (visited[r][c] || r < 0 || c < 0 || r >= n || c >= n) return;
    visited[r][c] = true;
    cout << r << " " << c;
    if (!flipped[r][c]) {
        for (int i = 0 ; i < levers[r][c].size() ; i++) {
            //check adjacent
            int x = levers[r][c][i].first;
            int y = levers[r][c][i].second;
            grid[x][y] = true;
            for (int j = 0 ; j < 4 ; i++) {
                if (visited[x+di[j]][y+dj[y]]) {
                    dfs(x+di[j],y+dj[y]);
                }
            }
        }
        flipped[r][c] = true;
    }
    for (int i = 0 ; i < 4; i++) {
        if (grid[r+di[i]][c+dj[i]]) {
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
        }
    }
    grid[0][0] = true;

    dfs(0, 0);

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (grid[i]) ans++;
        }
    }
    cout << ans << endl;    
} 