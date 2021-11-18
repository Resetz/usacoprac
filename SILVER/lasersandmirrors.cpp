#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R,C,N,M;

int arr[1000][1000];
int grid[1000][1000];

int di[] = {0, 0, 1, -1};
int dj[] = {-1, 1, 0 ,0};

bool good(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

int main() {
    cin >> R >> C >> N >> M;

    for (int i = 0 ; i < N ; i++) { /* / */
        int r,c;
        cin >> r >> c;
        r--; c--;
        grid[r][c] = 1;
    } 
    for (int i = 0 ; i < M ; i++) { /* \ */
        int r,c;
        cin >> r >> c;
        r--; c--;
        grid[r][c] = -1;
    }

    //start traverse from bottom right.
    int x, y, d;
    x = R-1;
    y = C-1;
    d = 1;
    while (good(x,y)) {
        if (grid[x][y] != 0) {
            d = ((d-1)+2)%4+1;
            if (grid[x][y] == -1) {
                if (d == 1) d = 2;
                else if (d == 2) d = 1;
                else if (d == 3) d = 4;
                else if (d == 4) d = 3;
            }
        }
        arr[x][y] = d;
        //cout << x << " " << y << " " << d << endl;
        x += di[d-1];
        y += dj[d-1];
    }
    /*
    for (int i = 0 ; i < R ; i++) {
        for (int j = 0 ; j < C ; j++) {
            if (grid[i][j] != 0) {
                cout << (grid[i][j] == 1 ? "/" : "\\") << " ";
            } else {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }*/
    //start traverse from top left
    x = 0;
    y = 0;
    d = 2;
    int found = 0;
    while (good(x,y)) {
        if (grid[x][y] != 0) {
            
            d = ((d-1)+2)%4+1;
            if (grid[x][y] == -1) {
                if (d == 1) d = 2;
                else if (d == 2) d = 1;
                else if (d == 3) d = 4;
                else if (d == 4) d = 3;
            }
        }
        if (arr[x][y] != 0) {
            if ((arr[x][y] == 1 && d == 2) || (arr[x][y] == 2 && d == 1) ||
                (arr[x][y] == 3 && d == 4) || (arr[x][y] == 4 && d == 3) ) {
                    if (true) {
                        cout << "Moo" << endl;
                    }
                    return 0;
                }
            if (grid[x][y] == 0) {
                cout << x+1 << " " << y+1 << " ";
                if (arr[x][y] == ((d-1)+2)%4+1) {
                    cout << "\\";
                } else {
                    cout << "/";
                }
                
                found++;
                cout << endl;
            }
        }
        //cout << x << " " << y << endl;
        x += di[d-1];
        y += dj[d-1];
    }
    if (found == 0) {
        for (int i = 0 ; i < 1 ; i++) {
            cout << "Moo ";
        } 
        if (true) {
            cout << "Moo";
        }
        cout << endl;
    }
}