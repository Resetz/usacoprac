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
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


using namespace std;

int m,n;

int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};

bool visited[100][100];

int main() {
    cin >> n >> m;

    

    bool grid[100][100];

    pair<int,int> start;
    pair<int,int> end;

    for (int i = 0 ; i < n ;i ++) {
        for (int j = 0 ; j < m; j++) {
            visited[i][j] = false;
            char c;
            cin >> c;
            if (c == 'B') {
                start = make_pair(i,j);
                grid[i][j] = false;
            } 
            if (c == 'C') {
                end = make_pair(i,j);
                grid[i][j] = false;
            }
            if (c == '.') {
                grid[i][j] = false;
            } else if (c == '*') {
                grid[i][j] = true;
            }
        }
    }

    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(start,0));

    while (true) {
        pair<pair<int,int>,int> p = q.front();
        q.pop();
        //cout << p.first.first << " " << p.first.second << " " << q.size() << endl;
        if (p.first.first == end.first&& p.first.second == end.second) {
            cout << p.second << endl;
            return 0;
        }

        if (p.first.first >= 0 && p.first.first < n && p.first.second >= 0 && p.first.second < m && !grid[p.first.first][p.first.second] && !visited[p.first.first][p.first.second]) {
            for (int i = 0; i < 4; i++) {
                q.push(make_pair(make_pair(p.first.first+di[i],p.first.second+dj[i]), p.second+1));
            }
            visited[p.first.first][p.first.second] = true;
        }
        
    }
}