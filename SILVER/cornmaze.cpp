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

#define make(r,c,time) make_pair(make_pair(r, c),time)
#define row first.first
#define col first.second
#define time second

using namespace std;

int main() {

    int di[] = { 0, 0,-1, 1};
    int dj[] = { 1,-1, 0, 0};

    int r,c;
    cin >> r >> c;

    int visited[300][300];
    int grid[300][300]; 
    //               r    c   time
    queue<pair<pair<int, int>,int>> q;  

    pair<int, int> tx[26];
    pair<int, int> ty[26];
    bool found[26];

    //cant take the same tp in the same direction twice.
    int tped[26];

    pair<int,int> start, end;

    for (int i = 0 ; i < r; i++) {
        for (int j = 0 ; j < c; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                grid[i][j] = 0;
                visited[i][j] = 2;
            } else if (c == '=') {
                grid[i][j] = 1;
                visited[i][j] = 0;
                end = make_pair(i,j);
            } else if (c == '.') {
                grid[i][j] = 1;
                visited[i][j] = 1;
            } else if (c == '@') {
                grid[i][j] = 1;
                visited[i][j] = 1;
                start = make_pair(i,j);
            } else {
                if (!found[c-'A']) {
                    tx[c-'A'] = make_pair(i,j);
                    grid[i][j] = c;
                    visited[i][j] = 0;
                    found[c-'A'] = true;
                } else {
                    ty[c-'A'] = make_pair(i,j);
                    grid[i][j] = c;
                    visited[i][j] = 0;
                }
            }
        }
    }

    q.push(make(start.first, start.second,0));

    while (true) {
        pair<pair<int,int>, int> p = q.front();
        //cout << p.row << " " << p.col << endl;
        q.pop();

        

        if (p.row == end.first && p.col == end.second) {
            cout << p.time;
            return 0;
        }

        if (p.row >= 0 && p.row < r && p.col >= 0 && p.col < c && (visited[p.row][p.col] < 2)) {
            pair<pair<int,int>,int> m;
            for (int i = 0; i < 4; i++) {
                bool validPosition = false;
                if (grid[p.row + di[i]][p.col + dj[i]] >= 'A') {
                    //which one is it;
                    int letter = grid[p.row + di[i]][p.col + dj[i]]- 'A';
                    
                    
                    if (tx[letter].first == p.row + di[i] && tx[letter].second == p.col + dj[i] && tped[letter] != 1) {
                        tped[letter] = 1;
                        m = make(ty[letter].first, ty[letter].second, p.time + 1);
                        validPosition = true;
                        visited[tx[letter].first][tx[letter].second]++;
                        //visited[ty[letter].first][ty[letter].second]++;
                    } else if (ty[letter].first == p.row + di[i] && ty[letter].second == p.col + dj[i] && tped[letter] != 2) {
                        tped[letter] = 2;
                        m = make(tx[letter].first, tx[letter].second, p.time + 1);
                        validPosition = true;
                        //visited[tx[letter].first][tx[letter].second]++;
                        visited[ty[letter].first][ty[letter].second]++;
                    }
                } else if (grid[p.row+di[i]][p.col+dj[i]] == 1) {
                    
                    m = make(p.row+di[i], p.col+dj[i], p.time + 1);
                    validPosition = true;
                }
                if (validPosition) {
                    q.push(m);
                }
            }
        }
        visited[p.row][p.col]++;
    }
}