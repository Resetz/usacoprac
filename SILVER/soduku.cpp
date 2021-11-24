#include <iostream>
#include <set>
#include <vector>

using namespace std;

int grid[9][9];
set<int> rows[9];
set<int> cols[9];
set<int> sub[3][3];

bool found = false;
void dfs(int r, int c) {

    if (grid[r][c] == 0) {
        for (int i = 1 ; i <= 9 ; i++) {
            if (rows[r].find(i) == rows[r].end() &&
                cols[c].find(i) == cols[c].end() &&
                sub[r/3][c/3].find(i) == sub[r/3][c/3].end()) 
                {
                    grid[r][c] = i;
                    cols[c].insert(i);
                    rows[r].insert(i);
                    sub[r/3][c/3].insert(i);

                    if (c == 8) {
                        if (r == 8) {
                            found = true;
                            return;
                        }
                        dfs(r+1, 0);
                    } else {
                        dfs(r, c+1);
                    }

                    if (found) {return;}

                    cols[c].erase(i);
                    rows[r].erase(i);
                    sub[r/3][c/3].erase(i);
                    grid[r][c] = 0;
            }
        }
    } else {
        if (c == 8) {
            if (r == 8) {
                found = true;
                return;
            }
            dfs(r+1, 0);
        } else {
            dfs(r, c+1);
        }
        if (found) return;
    }
    
}

int main() {
    for (int i = 0 ; i < 9 ; i++) {
        for (int j = 0 ; j < 9 ; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != 0) {
                rows[i].insert(grid[i][j]);
                cols[j].insert(grid[i][j]);
                sub[i/3][j/3].insert(grid[i][j]);
            }
        }
    }

    dfs(0,0);
    if (found) {
        for (int i=0; i < 9 ; i++) {
            for (int j = 0 ; j < 9 ; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO SOLUTION" << endl;
    }
}