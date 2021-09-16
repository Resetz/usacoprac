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

int grid[31][31];
int found = 0;
int amt = 0;
bool finish = false;
int n;
vector<pair<int,int>> s(900);
vector<pair<int,int>> starting;
int di[4] = {1, 1, -1, -1};
int dj[4] = {1, -1, 1, -1};

int check(int i, int j) {
    if (i >= 0 && j >= 0 && i < n && j < n) {
        return grid[i][j];
    } else {
        return -1;
    }
}

void dfs(int i, int j) {
    if (finish) return;
    if (i >= 0 && j >= 0 && i < n && j < n) {
        //cout << found << " (" << i << ", " << j << ") -> ";
        s[found].first = i; s[found].second = j;
        if (found == amt || finish) {
            finish = true;
            return;
        }
        found++;
        //top left
        for (int k = 0; k < 4; k++) {
            if (check(i + di[k], j + dj[k]) == 2 && check(i + di[k]*2, j + dj[k]*2) == 1) {
                grid[i + di[k]][j + dj[k]] = 1;
            //cout << "hopping to " << "(" << i + di[k]*2 << ", " << j + dj[k]*2 << ")";
                dfs(i + di[k]*2, j + dj[k]*2);
                if (finish) {
                    return;
                }
                grid[i + di[k]][j + dj[k]] = 2;
            }
        }
        found--;
        //cout << " <- ";
        

    }
}

int main() {
    cin >> n;
    s.resize(n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            char c;
            cin >> c;
            if (c == '+') {
                grid[i][j] = 1;
            } else if (c == 'K') {
                starting.push_back(make_pair(i,j));
                grid[i][j] = 0;
            } else if (c == 'o') {
                grid[i][j] = 2;
                amt++;
            } else {
                grid[i][j] = -1;
            }
        }
    }
    for (int i = 0 ; i < starting.size() ; i++) {
        dfs(starting[i].first, starting[i].second);
        //cout << endl;
    }
    if (found) {
        for (int i = 0 ; i < amt + 1 ; i++) {
            cout << s[i].first + 1 << " "  << s[i].second  + 1<< endl;
        }
    } else {
        cout << "impossible" << endl;
    }
    cout << endl;
}