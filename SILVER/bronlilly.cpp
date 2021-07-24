
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

using namespace std;

int grid[30][30];
int dx[8];
int dy[8];

struct a {
    int x;
    int y;
    int t;
};
vector<a> q;
bool visited[30][30];
int main() {
    int n,m;
    int x, y;
    int startx, starty;
    int endx, endy;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 3) {
                startx = i;
                starty = j;
            } if (grid[i][j] == 4) {
                endx = i;
                endy = j;
            }
        }
    }
    int len = 0;
    if (x == y) {
        len = 4;
        dx[0] = x;
        dy[0] = y;

        dx[1] = -x;
        dy[1] = y;

        dx[2] = x;
        dy[2] = -y;

        dx[3] = -x;
        dy[3] = -y;
    } else {
        len = 8;
        dx[0] = x;
        dy[0] = y;

        dx[1] = -x;
        dy[1] = y;

        dx[2] = x;
        dy[2] = -y;

        dx[3] = -x;
        dy[3] = -y;

        dy[4] = x;
        dx[4] = y;

        dy[5] = -x;
        dx[5] = y;

        dy[6] = x;
        dx[6] = -y;

        dy[7] = -x;
        dx[7] = -y;
    }
    a b;
    b.x = startx;
    b.y = starty;
    b.t = 0;
    q.push_back(b);
    while (true) {
        a s = q[0];
        if (s.x == endx && s.y == endy) {
            cout << s.t;
            return 0;
        } 
        q.erase(q.begin());
        

        for (int i = 0; i < len; i++) {
            if (s.x + dx[i] >= 0 && s.x + dx[i] < n && s.y + dy[i] >= 0 &&s.y + dy[i] < m &&grid[s.x + dx[i]][s.y + dy[i]] != 0 &&grid[s.x + dx[i]][s.y + dy[i]] != 2 &&!visited[s.x + dx[i]][s.y + dy[i]]) 
             {
                a add;
                add.x = s.x + dx[i];
                add.y = s.y + dy[i];
                add.t = s.t + 1;
                visited[add.x][add.y] = true;
                q.push_back(add);
            }
        }

    }
}