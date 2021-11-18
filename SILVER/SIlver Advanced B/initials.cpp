#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int h, w;

bool grid[100][100];
bool visited[100][100];

int di[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dj[] = {0, 0, 1, -1, -1, 1, 1, -1};


bool check(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

void ff(int x, int y) {
    bool type = grid[x][y];
    queue<pair<int,int>> q;
    q.push({x,y});
    while (!q.empty()) {
        pair<int,int> t = q.front();
        q.pop();
        if (!check(t.first, t.second) || visited[t.first][t.second] || (grid[t.first][t.second] != type)) continue;
        visited[t.first][t.second] = true;
        for (int i = 0 ; i < 4; i++) {
            q.push({t.first+di[i],t.second+dj[i]});
        }
    }
}

int main() {
    cin >> h >> w;

    for (int i = 0 ; i < h ; i++) {
        for (int j = 0 ; j < w ; j++) {
            char c;
            cin >> c;
            grid[i][j] = c == '*';
        }
    }
    
    int amt = 0;
    for (int i = 0 ; i < h ; i++) {
        for (int j = 0 ; j < w; j++) {
            if (visited[i][j]) continue;
            ff(i,j);
            amt++;
        }
    }
    if (amt == 2) {
        cout << "E";
    } else if (amt == 3) {
        cout << "D";
    } else {
        cout << "B";
    }
    cout << endl;
}