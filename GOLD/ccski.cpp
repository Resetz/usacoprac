#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
vector<vector<int>> grid;
vector<vector<bool>> good;
vector<vector<bool>> visited;
vector<pair<int,int>> starts;

int di[4] = {0,0,-1,1};
int dj[4] = {1,-1,0,0};

int go(int k) {
    queue<pair<int,int>> q;
    q.push(starts[0]);
    while (!q.empty()) {
        pair<int,int> p = q.front(); q.pop();
        if (visited[p.first][p.second]) continue;
        visited[p.first][p.second] = true;

        for (int i = 0; i < 4; i++) {
            int newx = p.first + di[i];
            int newy = p.second + dj[i];
            if (newx >= 0 && newy >= 0 && newx < n && newy < m) {
                if (abs(grid[newx][newy] - grid[p.first][p.second]) < k) {
                    q.push({newx,newy});
                }
            } 
        }
    }
}
int main() {

    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    good.resize(n, vector<bool>(m));
    visited.resize(n, vector<bool>(m));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++)
            cin >> grid[i][j];
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++){ 
            int k = 0;
            cin >> k;
            good[i][j] = k == 1;
            starts.push_back({i,j});
        }
    }

    int high = 1'000'000'000;
    int low = 0;
    int ans = -1;
    while (high >= low) {
        int mid = low + (high - low) / 2;
        if (go(mid)) {

        }
    }
    

}