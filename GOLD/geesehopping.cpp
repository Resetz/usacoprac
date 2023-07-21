#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
int di[8] = {-2,-2,-1,-1,1,1,2,2};
int dj[8] = {1,-1,2,-2,2,-2,1,-1};
int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    pair<int,int> start;
    pair<int,int> finish;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 3) start = {i,j};
            if (grid[i][j] == 4) finish = {i,j};
        }
    }

    priority_queue<pair<pair<int,int>, pair<int,int>>> pq;
    pq.push({{0,0},start}); 
    vector<vector<int>> visited(n, vector<int>(m, false));
    pair<int,int> ans = {-1,-1};
    while (!pq.empty()) {
        pair<pair<int,int>, pair<int,int>> p = pq.top();
        pq.pop();
        if (visited[p.second.first][p.second.second]) {
            continue;
        }
        visited[p.second.first][p.second.second] = true;
        p.first.first *= -1;
        p.first.second *= -1;
        //cout << p.second.first << " " << p.second.second << " " << p.first.first << " " << p.second.second << endl;
        if (p.second == finish) {
            ans = p.first; break;
        }
        
        for (int i = 0 ; i < 8 ; i++) {
            int x,y;
            x = p.second.first + di[i];
            y = p.second.second + dj[i];
            if (x >= 0 && x < n && y >= 0 && y < m) {
                if (grid[x][y] == 2) {
                    continue;
                } 
                pq.push({{-(p.first.first+(grid[x][y] == 0)), -(p.first.second+1)}, {x,y}});
            }
        }
    }
    cout << ans.first << endl;
    if (ans.first == -1) return 0;
    cout << ans.second << endl;

    vector<vector<int>> cur(n, vector<int>(m, INT_MAX));
    vector<vector<int>> amt(n, vector<int>(m, 0));
    
    while (!pq.empty()) {
        pq.pop();
    }

    pq.push({{0,1},start}); 
    while (!pq.empty()) {
        pair<pair<int,int>, pair<int,int>> p = pq.top();
        p.first.first *= -1;
        pq.pop();
        if (cur[p.second.first][p.second.second] < p.first.first) {
            continue;
        } else {
            if (cur[p.second.first][p.second.second] == p.first.first) {
                amt[p.second.first][p.second.second] += p.first.second;
                continue;
            } else {
                amt[p.second.first][p.second.second] = p.first.second;
            }
            cur[p.second.first][p.second.second] = p.first.first;
        }
        //cout << p.second.first << " " << p.second.second << " " << amt[p.second.first][p.second.second] << " " << p.first.second << endl; 

        for (int i = 0 ; i < 8 ; i++) {
            int x,y;
            x = p.second.first + di[i];
            y = p.second.second + dj[i];
            if (x >= 0 && x < n && y >= 0 && y < m) {
                if (grid[x][y] == 2) {
                    continue;
                } 
                pq.push({{-(p.first.first+(grid[x][y] == 0)), p.first.second}, {x,y}});
            }
        }
    }
    cout << amt[finish.first][finish.second] << endl;
}