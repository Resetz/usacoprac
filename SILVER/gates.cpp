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

bool grid[4001][4001];
string directions;
int n;
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};
int total;
bool visited[4001][4001];


void ff(int r, int c) {
    queue<pair<int,int>> q;
    q.push(make_pair(r,c));

    while (q.size() > 0) {
        pair<int,int> p = q.front();
        q.pop();

        if (p.first < 4001 && p.first >= 0 && p.second < 4001 && p.second >= 0) {
            if (!grid[p.first][p.second] && !visited[p.first][p.second]) {
                visited[p.first][p.second] = true;
                total++;
                q.push(make_pair(p.first+di[0],p.second+dj[0]));
                q.push(make_pair(p.first+di[1],p.second+dj[1]));
                q.push(make_pair(p.first+di[2],p.second+dj[2]));
                q.push(make_pair(p.first+di[3],p.second+dj[3]));
            }    
        }
    }
}

int main() {
    cin >> n;
    cin >> directions;
    int row = 2000;
    int col = 2000;

    for (int i = 0; i < n; i++) {
        if (directions[i] == 'N') {
            grid[row+di[0]][col+dj[0]] = true;
            grid[row+di[0]+di[0]][col+dj[0]+dj[0]] = true;
            row += di[0]*2;
            col += dj[0]*2;
        } else if (directions[i] == 'S') {
            grid[row+di[1]][col+dj[1]] = true;
            grid[row+di[1]+di[1]][col+dj[1]+dj[1]] = true;      
            row += di[1]*2;
            col += dj[1]*2;
        } else if (directions[i] == 'W') {
            grid[row+di[2]][col+dj[2]] = true;
            grid[row+di[2]+di[2]][col+dj[2]+dj[2]] = true;
            row += di[2]*2;
            col += dj[2]*2;
        } else if (directions[i] == 'E') {
            grid[row+di[3]][col+dj[3]] = true;
            grid[row+di[3]+di[3]][col+dj[3]+dj[3]] = true;
            row += di[3]*2;
            col += dj[3]*2;
        }
    }
    //simple flood fill
    
    int ans = 0;
    for (int i = 0; i < 2002; i++) {
        for (int j = 0; j < 2002; j++) {
            if (!visited[i][j] && grid[i][j] != 1) {
                //floodfill;
                ff(i,j);
                ans++;
            }
        }
    }
    cout << ans - 1;
}