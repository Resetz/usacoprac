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

#define row first.first
#define col first.second
#define time second.first
#define direction second.second
#define make_node(r,c,t,d) make_pair(make_pair(r,c),make_pair(t,d))

//          r  l  u  d
int di[] = {0, 0, 1,-1};
int dj[] = {1,-1, 0, 0};

int main() {
    int c;
    int r;
    cin >> c >> r;
    bool grid[100][100];
    
    unsigned int timeGrid[100][100];

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            timeGrid[i][j] = 0xFFFFFFFF;
        }
    }

    pair<int, int> start, end;
    bool started = false;
    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < c ; j ++) {
            char temp;
            cin >> temp;
            if (temp == '.') {
                grid[i][j] = true;
            } else if (temp == '*') {
                grid[i][j] = false;
            } else {
                if (!started) {
                    grid[i][j] = true;
                    start = make_pair(i, j);
                    started = true;
                } else {
                    grid[i][j] = true;
                    end = make_pair(i, j);
                }
            }
        }
    }
    //          r   c        time dir
    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push(make_pair(make_pair(start.first, start.second), make_pair(0, 0)));
    q.push(make_pair(make_pair(start.first, start.second), make_pair(0, 1)));
    q.push(make_pair(make_pair(start.first, start.second), make_pair(0, 2)));
    q.push(make_pair(make_pair(start.first, start.second), make_pair(0, 3)));

    while (q.size() != 0) {
        pair<pair<int,int>,pair<int,int>> p = q.front();
        q.pop();
        int cr = p.row + di[p.direction];
        int cc = p.col + dj[p.direction];
        while (cr < r && cr > -1 && cc < c && cc > -1 && grid[cr][cc]) {
            if (timeGrid[cr][cc] > p.time) {
                timeGrid[cr][cc] = p.time;
                //both directions
                if (p.direction == 0 || p.direction == 1) {
                    q.push(make_node(cr, cc, p.time+1, 3));
                    q.push(make_node(cr, cc, p.time+1, 4));
                } else {
                    q.push(make_node(cr, cc, p.time+1, 0));
                    q.push(make_node(cr, cc, p.time+1, 1));
                }
            }
            cr+=di[p.direction];
            cc+=dj[p.direction];
        }
        
    }
    cout << timeGrid[end.first][end.second];
}