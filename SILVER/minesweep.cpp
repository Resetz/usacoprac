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
#include <iomanip>

#define all(n) n.begin(), n.end()
using namespace std;

int grid[30][30];
bool placed[30][30];
int begin[30];
int n, m;
int bombs;
int num_placed = 0;
int done = 0;
int impossible = false;

bool check(int r, int c) {
    if (r >= 0 && r < n && c >= 0 && c < m) {
        return grid[r][c] > 0;
    } else {
        return true;
    }
}

void dmine(int r,int c,int d) {
    for (int i = r-1; i <= r+1; i++) {
        for (int j = c-1; j <= c+1; j++) {
            if (i >= 0 && i < n && j >= 0 && j < m) grid[i][j]+=d;
        }
    } 
}

bool surround(int r, int c) {
    for (int i = r-1; i <= r+1; i++) {
        for (int j = c-1; j <= c+1; j++) {
            if (!check(i,j)) return false;
        }
    } 
    return true;
}

bool valid() {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m  ; j++) {
            if (grid[i][j] != 0) return false;
        }
    }
    return true;
}

void dfs(int r, int c) {

    // check if bomb placement works
    if (bombs == num_placed) {
        if (valid()) done = true;
        else {
            return;
        }
    } 
    // pruning
    if (r > 0 && c > 1 && grid[r-1][c-2]>0) {
        return;
    }
    if (c >= m) {
        if (r > 0 && grid[r-1][c-1]>0) return;
        r++, c = 0;
    }

    if (grid[r][c] && num_placed < bombs && surround(r,c)) {
        dmine(r,c,-1);
        num_placed++;
        placed[r][c] = true;
        dfs(r,c+1);
        if (done) return;
        placed[r][c] = false;
        num_placed--;
        dmine(r,c,1);
    }
    
    dfs(r,c+1);
    /*
    bool first = true;
    for (int i = r; i < n ; i++) {
        for (int j = 0; j < m; j++) {
            if (first) {j = c; first = false;}

            if (placed[i][j]) {
                continue;
            } else {
                if (surround(i,j)) {
                    placed[i][j] = true;
                    num_placed++;
                    sub1(i,j);

                    dfs(i,j);
                    if (done || impossible) {
                        return;
                    }

                    placed[i][j] = false;
                    num_placed--;
                    add1(i,j);
                }
            }
        }
        bool skip = false;
               
        if (skip) {
            return;
        }
    }*/
    return;
}

int main() {
    cin >> n >> m >> bombs;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            placed[i][j] = false;
        }
    }

    dfs(0, 0);

    if (done) {
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (placed[i][j]) cout << i+1 << " " << j+1 << endl;
            }
        }
    } else {
        cout << "NO SOLUTION";
    }
}