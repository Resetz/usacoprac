#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int r,c;
vector<vector<bool>> v;

int clx[] = {0,1,-1,0,0};
int cly[] = {0,0,0,1,-1};
bool res = false;
vector<vector<bool>> ans;

int check(int x, int y) {
    if (x >= 0 && y >= 0 && x < r && y < c) {
        return v[x][y];
    } else {
        return 2;
    }
}
void set(int x, int y) {
    if (check(x,y) != 2) v[x][y] = !v[x][y];
}

void backtrack(int x, int y) {
    if (res) return;
    if (check(x-1, y-1) != 2) {
        if (check(x-1, y-1)) {
            return;
        }
    }

    if (x == r && y == 0) {
        bool good = true;
        for (int i = 0 ; i < r; i++) {
            for (int j = 0 ; j < c; j++) {
                //cout << v[i][j] << " ";
                if (v[i][j]) {
                    good = false;
                }
            }
            //cout << endl;
        }
        if (good) {
            res = true;
        }
     //cout << endl;
        return;
    }

    if (y == c-1) {
        backtrack(x+1, 0);
    } else {
        backtrack(x, y+1);
    }
    if (res) return;
    for (int i = 0 ; i < 5 ; i++) {
        set(x+clx[i],y+cly[i]);
    }

    ans[x][y] = true;
    if (y == c-1) {
        backtrack(x+1, 0);
    } else {
        backtrack(x, y+1);
    }

    for (int i = 0 ; i < 5 ; i++) {
        set(x+clx[i],y+cly[i]);
    }
    if (!res) {
        ans[x][y] = false;
    }
    /*
    ans[x][y] = true;
    if (y == c-1) {
        backtrack(x+1, 0);
    } else {
        backtrack(x, y+1);
    }
    if (res) return;

    for (int i = 0 ; i < 5 ; i++) {
        set(x+clx[i],y+cly[i]);
    }
    ans[x][y] = false;
    if (y == c-1) {
        backtrack(x+1, 0);
    } else {
        backtrack(x, y+1);
    }*/

}  
int main() {
    cin >> r >> c;

    v.resize(r, vector<bool>(c, false));
    ans.resize(r, vector<bool>(c, false));

    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < c ; j++) { 
            int in;
            cin >> in;
            v[i][j] = in == 1;
        }
    }
    backtrack(0,0);
    if (res) {
        for (int i = 0 ; i < r ; i++) {
            for (int j = 0 ; j < c; j ++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    
}