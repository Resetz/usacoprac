//prac

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

int dc[] = {-1, 0};
int dr[] = {0, 1};

int arr[500];
int grid[500][500];
int n;
void dfs(int row, int col, int num, int left) {
    if (row < n && col < n && row >= 0 && col >= 0 && grid[row][col] == 0 && left > 0) {
        // go left
        grid[row][col] = num;
        if (grid[row + dr[0]][col + dc[0]] == 0 && col + dc[0] >= 0) {
            dfs(row + dr[0], col + dc[0], num, left - 1);
        }
        else {
            dfs(row + dr[1], col + dc[1], num, left - 1);
        }
    } 
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i ++) { 
        cin >> arr[i];
        dfs(i, i, arr[i], arr[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
