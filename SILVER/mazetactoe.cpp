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

int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};

int n;
#define make(i,j,k) make_pair(i,make_pair(j,k))
#define type first
#define gridX second.first
#define gridY second.second
pair<int,pair<int,int>> grid[25][25];
set<int> winning;
bool visited[25][25][19683] /*3^9 = 19683*/;
long long pow3[10];

bool checkForWin(int g[3][3]) {
    //brute force check
    for (int i = 0 ; i < 3; i++) {
        if (g[i][0] == 2 && g[i][1] == 1 && g[i][2] == 1) return true;
        if (g[i][2] == 2 && g[i][1] == 1 && g[i][0] == 1) return true;

        if (g[0][i] == 2 && g[1][i] == 1 && g[2][i] == 1) return true;
        if (g[2][i] == 2 && g[1][i] == 1 && g[0][i] == 1) return true;
    }

    if (g[0][0] == 2 && g[1][1] == 1 && g[2][2] == 1) return true;
    if (g[2][2] == 2 && g[1][1] == 1 && g[0][0] == 1) return true;
    if (g[0][2] == 2 && g[1][1] == 1 && g[2][0] == 1) return true;
    if (g[2][0] == 2 && g[1][1] == 1 && g[0][2] == 1) return true;
    return false;
}

bool checkForWinv2(int g) {
    int check[3][3];
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ;j < 3; j++) {
            check[i][j] = g % 3;
            g /= 3;
        }
    }
    return checkForWin(check);

}

int gtoi(int a[3][3]) {
    //basically from base-3 to base-10;
    int ret =0 ;
    int num = 0;
    for (int i = 0 ; i < 3; i++ ){
        for (int j = 0 ; j < 3; j++) {
            ret += a[i][j]*pow3[num];
            num++;
        }
    }
    return ret;
}

void dfs(int r, int c, int g[3][3]) {
    int val = gtoi(g);
    
    if (r < 0 || r >= n || c < 0 || c >= n || visited[r][c][val]) {
        return;
    }
    visited[r][c][val] = true;
    
    
    if (grid[r][c].type != 0) {
        //cout << r << ", " << c << ", " << val << "\n";
        if (r == 3 && c == 1) {
            //test;
            cout << "";
        }
        
        int newg[3][3];
        for (int i = 0 ; i < 3; i++) {
            for (int j = 0 ; j < 3; j++) {
                newg[i][j] = g[i][j];
            }
        }

        if (grid[r][c].type != 1) {
            int row = grid[r][c].gridX;
            int col = grid[r][c].gridY;
            int value = newg[row][col];
            if (value == 0) {
                newg[row][col] = grid[r][c].type-1;
                
                if (checkForWin(newg) && winning.find(val) == winning.end()) {
                    winning.insert(val);
                    /*
                    cout << winning.size() << endl;
                    for (int i = 0 ; i < 3; i++) {
                        for (int j = 0 ; j < 3; j++) {
                            cout << newg[i][j] << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                    */
                    return;
                }
            }
            
        }
        for (int i = 0; i < 4; i++) {
            int tempg[3][3];
            cout << "pushed " << r+di[i] << " " << c+dj[i] << endl; 
            for (int i = 0 ; i < 3; i++) {
                for (int j = 0 ; j < 3; j++) {
                    tempg[i][j] = newg[i][j];
                    cout << newg[i][j] << " ";

                }
                cout << endl;
            }
            dfs(r+di[i],c+dj[i],tempg);
            
        }   
    }

}

void dfsv2(int r, int c, int g)
{
    if (r < 0 || r >= n || c < 0 || c >= n || visited[r][c][g]) {
        return;
    }
    visited[r][c][g] = true;
    if (grid[r][c].type != 0) {
        if (grid[r][c].type != 1) {
            int row = grid[r][c].gridX;
            int col = grid[r][c].gridY;

            int index = row*3+col;
            int val = (g/pow3[index])%3;
            if (val == 0) {
                g = (g%pow3[index]) + pow3[index] * (grid[r][c].type-1)  + (g - g % pow3[index+1]);
                if (!visited[r][c][g] && checkForWinv2(g)) {
                    winning.insert(g);
                    return;
                } 
                visited[r][c][g] = true;
            }
            
        }
        for (int i = 0; i < 4; i++) {
            dfsv2(r+di[i],c+dj[i],g);
        }

    }
}
int main() {

    pow3[0] = 1;
    for (int i = 1 ; i < 10; i++) {
        pow3[i] = pow3[i-1] * 3;
    }
    
    pair<int,int> start;
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j*3] == '#') {
                grid[i][j] = make(0,0,0);
            } else {
                grid[i][j] = make(1,0,0);
                if (s[j*3] == 'O') {
                    grid[i][j] = make(2,s[j*3+1]-'1',s[j*3+2]-'1');
                } else if (s[j*3] == 'M') {
                    grid[i][j] = make(3,s[j*3+1]-'1',s[j*3+2]-'1');
                } else if (s[j*3] == 'B') {
                    start.first = i;
                    start.second = j;
                }
            }
        }
    }
    dfsv2(start.first, start.second, 0);
    cout << winning.size() << endl;
}