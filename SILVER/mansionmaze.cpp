#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int di[] = {2,-2,0,0};
int dj[] = {0,0,2,-2};

int main( ) {
    int n, m;
    cin >> n >> m;
    n = 2*n+2;
    m = 2*m+1;
    int temp = n;
    n = m;
    m = temp;
    vector<vector<bool>> grid(n, vector<bool>(m, false));
    cin >> ws;
    cin >> noskipws;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            char c;
            cin >> c;
            if (c == ' ') grid[i][j] = true;
        }
    }
    /*for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }*/

    queue<pair<int,pair<int,int>>> q;
    for (int i = 0; i < n ; i++) {
        //cout << grid[i][m-2] << endl;
        if (grid[i][m-2]) {
            q.push({1, {i, m-3}});
        } 
        if (grid[i][0]) {
            q.push({1, {i, 1}});
        }
    }
    for (int i = 0; i < m ; i++) {
        if (grid[n-1][i]) {
            q.push({1, {n-2,i}});
        } 
        if (grid[0][i]) {
            q.push({1, {1, i}});
        }
    }

    vector<vector<int>> ans(n, vector<int>(m, -1));
    while (!q.empty()) {

        pair<int,pair<int,int>> p = q.front();
        q.pop();
        int x = p.second.first;
        int y = p.second.second;
        if (x < 0 || y < 0 || x >= n || y >= m || !grid[x][y]) {
            continue;
        }

        if (ans[p.second.first][p.second.second] == -1) {
            ans[p.second.first][p.second.second] = p.first;

            for (int i = 0 ; i < 4 ; i++) {
                if (grid[p.second.first+di[i]/2][p.second.second+dj[i]/2]) {
                    q.push({p.first+1, {p.second.first+di[i], p.second.second+dj[i]}});
                }
            }
        } 
        
    }
    int a = ans[0][0];
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            a = max(ans[i][j], a);
        }
    }
    cout << a << endl;
}