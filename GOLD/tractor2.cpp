#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int di[4] = {1,0,-1,0};
int dj[4] = {0,-1,0,1};
vector<vector<int>> grid;

int go(int k) {
    vector<vector<int>> vis(n, vector<int>(n, 0));
    queue<pair<int,int>> q;
    int m = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (!vis[i][j]) {
                q.push({i,j});
                int cur = 0;
                while (!q.empty()) {
                    pair<int,int> p = q.front();
                    q.pop();
                    if (vis[p.first][p.second]) continue;
                    vis[p.first][p.second] = true;
                    cur++;
                    for (int l = 0 ; l < 4 ; l++) {
                        int newx = p.first + di[l];
                        int newy = p.second + dj[l];
                        if (newx < 0 || newx >= n || newy < 0 || newy >= n) continue;
                        if (!vis[newx][newy]) {
                            if (abs(grid[p.first][p.second] - grid[newx][newy]) <= k) {
                                q.push({newx,newy});
                            }
                        }
                    }
                }

                m = max(cur, m);
            }
        }
    }
    //cout << k << " " << m << endl;
    return m >= ((n*n+1)/2);
}
int main() {
    cin >> n;
    grid.resize(n, vector<int>(n));

    int high = 0;
    for (int i = 0; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> grid[i][j];
            high = max(grid[i][j], high);
        }
    }

    int low = 0;
    int ans = 0;
    while (high >= low) {
        int mid = low + (high - low) / 2;
        if (go(mid)) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    cout << ans << endl;
}