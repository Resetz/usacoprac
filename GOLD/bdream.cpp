#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
    int x,y;
    int orange;
    int direction;
    int time;
} state;

class Compare
{
public:
    bool operator() (state a, state b)
    {
        return a.time > b.time;
    }
};

int di[] = {0,-1,1,0};
int dj[] = {1,0,0,-1};
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> grid[i][j];
        }
    }
    
    priority_queue<state> pq;
    vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(4)));
    while (!pq.empty()) {
        state s = pq.top();

        if (vis[s.x][s.y][s.direction]) {
            continue;
        }

        int curtile = grid[s.x][s.y];
        for (int i = 0; i < 4 ; i++) {
            int newx = s.x + di[i];
            int newy = s.y + dj[i];
            if (newx >= 0 && newy >= 0 && newx < n && newy < m) {
                int newtile = grid[newx][newy];
                if (i == s.direction && curtile == 4 && newtile == 4) {
                    pq.push(state{newx,newy,s.orange,s.direction,s.time});
                }
            }
            
        }
    }
}