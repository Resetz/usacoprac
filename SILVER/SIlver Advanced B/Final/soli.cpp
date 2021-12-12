#include <iostream>
#include <vector>
using namespace std;

int grid[7][7];

int di[] = {-1, 0};
int dj[] = {0, 1};

int cur = 0;
int ans = 0;
int n;

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return;
    }
    cur += grid[x][y];
    if (x == 0 && y == n-1) {
        ans = max(cur, ans);
        cur -= grid[x][y];
        return;
    }
    for (int i = 0 ; i < 2 ; i++) {
        dfs(x+di[i], y+dj[i]);
    }
    cur -= grid[x][y];
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            string s;
            cin >> s;
            if (s[0] == 'A') grid[i][j] = 1;
            else if (s[0] == 'T') grid[i][j] = 10;
            else if (s[0] == 'J') grid[i][j] = 11;
            else if (s[0] == 'Q') grid[i][j] = 12;
            else if (s[0] == 'K') grid[i][j] = 13;
            else grid[i][j] = s[0] - '0';
            //cout << grid[i][j] << " ";
        }
        //cout << endl;
    }
    dfs(n-1, 0);
    cout << ans << endl;
}