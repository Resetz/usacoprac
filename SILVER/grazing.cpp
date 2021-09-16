#include <iostream>
#include <unordered_set>

using namespace std;

int grid[5][5] = {0};
unordered_set<int> s;

int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

void dfs(int r, int c, int d, int k) {
    if (d <= 5) {
        if (r >= 5 || c >= 5 || c < 0 || r < 0) {
            return;
        }
        k *= 10;
        k += grid[r][c];
        for (int i = 0 ; i < 4 ; i++) {
            dfs(r+di[i], c+dj[i], d+1, k);
        }
    } else {
        s.insert(k);
        //cout << "inserting " << k << endl;
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5; j++) {
            dfs(i, j, 0, 0);
        }
    }
    cout << s.size() << endl;
}