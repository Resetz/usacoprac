
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

void solve() {
    queue<pair<int,int>> q;
    int r,c;
    cin >> r;
    c = r;

    int di[] = {0,0,1,-1};
    int dj[] = {1,-1,0,0};

    bool grid[1000][1000];
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char in;
            cin >> in;
            if (in == '*') {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            
            if (grid[i][j]) {
                q.push(make_pair(i, j));
                count++;
                while (q.size() != 0) {
                    pair<int,int> p = q.front();
                    q.pop();
                    if (grid[p.first][p.second] && (p.first > -1 && p.second > -1 && p.first < r && p.second < r)) {
                        grid[p.first][p.second] = false;
                        
                        for (int k = 0; k < 4; k++) {
                            q.push(make_pair(p.first+di[k], p.second+dj[k]));
                        }
                    } 
                }
            } else {
                continue;
            }
        }
    }
    cout << count;
}

int main() {
    solve();
}
