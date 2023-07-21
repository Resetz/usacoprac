#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r,c;



vector<vector<int>> grid;
vector<vector<int>> vis;
vector<vector<bool>> hit;
vector<vector<int>> siz;
vector<int> sizes;
int di[4] = {0, -1, 0, 1};
int dj[4] = {-1,0, 1, 0};
int k = 0;
int id = 1;
void ff(int row, int col) {
    if (!(row >= 0 && row < r && col >= 0 && col < c)) return;
    if (vis[row][col]) return;
    int adj[4];
    int c = 0;
    for (int i = 1 ; i <= 8 ; i = i * 2, c++) {
        adj[c] = !(grid[row][col] & i);
    }
    hit[row][col] = true;
    vis[row][col] = id;
    k++;
    for (int i = 0 ; i < 4; i++) {
        if (adj[i]) {
            ff(row+di[i],col+dj[i]); 
        }
    }
}

void fil(int row, int col) {
    if (!(row >= 0 && row < r && col >= 0 && col < c)) return;
    if (!hit[row][col]) return;
    hit[row][col] = false;
    siz[row][col] = k;
    //cout << row << " " << col << " " << k << endl;
    for (int i = 0 ; i < 4; i++) {
        fil(row+di[i],col+dj[i]);
    }
}
int main() {
    cin >> c >> r;
    grid.resize(r, vector<int>(c));
    vis.resize(r, vector<int>(c));
    hit.resize(r, vector<bool>(c));
    siz.resize(r, vector<int>(c, 0));
    for (int i = 0 ; i < r; i++) {
        for (int j = 0 ; j < c ; j++) cin >> grid[i][j];
    }

    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < c ; j++) {
            if (!vis[i][j]) {
                ff(i,j);
            
                //cout << k << endl;
                sizes.push_back(k);
                id++;
                fil(i,j);
                k = 0;
            }
        }
    }

    sort(sizes.begin(), sizes.end());
    cout << sizes.size() << endl;
    cout << sizes[sizes.size()-1] << endl;

    int best = 0;
    for (int i = 0 ; i < r; i++) {
        for (int j = 0 ; j < c ; j++) {
            if (j != c-1 && vis[i][j] != vis[i][j+1]) {
                best = max(siz[i][j]+siz[i][j+1], best);
            }
            if (i != r-1 && vis[i][j] != vis[i+1][j]) {
                best = max(siz[i][j]+siz[i+1][j], best);
            }
        }
        //cout << endl;
    }
    cout << best << endl;

}