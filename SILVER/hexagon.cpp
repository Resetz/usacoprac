#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <set>
#include <algorithm>

using namespace std;

int n, h, l;

int grid[200][200] = {0};

int di[] = {1, -1, -1, 1, 2, -2};
int dj[] = {1, -1, 1, -1, 0, 0};

set<int> v;

bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < 200 && y < 200;
    
}
int main() {
    cin >> n >> h >> l;
    int posx = 0;
    int posy = 0;
    
    int cnter = 1;
    for (int i = 0 ; i < n ; i++)  {
        for (int j = n-i ; j < n-i+(n+i)*2 ; j+=2) {
            grid[j][i] = cnter;
            if (cnter == h) {
                posx = j;
                posy = i;
            }
            cnter++;
        }
    }

    for (int i = n*2-2 ; i >= n ; i--) {
        int go = i - n;
        for (int j = n-go ; j < n-go+(n+go)*2 ; j+=2) {
            grid[j][n*2-2-i+n] = cnter;
            if (cnter == h) {
                posx = j;
                posy = n*2-2-i+n;
            }
            cnter++;
        }
    }
    /*
    for (int i = 0 ; i < n*4; i++) {
        for (int j = 0 ; j < n*4 ; j++) {
            cout << setw(2) << grid[i][j] << " ";
        }
        cout << endl;
    }
*/
    cnter--;
    
    queue<pair<pair<int,int>,int>> q;
    q.push({{posx, posy},0});
    v.insert(h);


    vector<int> ans;
    while (q.size() > 0) {
        pair<pair<int,int>,int> p = q.front();
        q.pop();
        //cout << p.second << " " << grid[p.first.first][p.first.second] << endl;
        
        
        if (p.second == l) {
            ans.push_back(grid[p.first.first][p.first.second]);
            continue;
        }
        for (int i = 0 ; i < 6 ; i++) {
            int newx = p.first.first+di[i];
            int newy = p.first.second+dj[i];
            if (check(newx,newy)) {
                int num = grid[newx][newy];
                if (num != 0) {
                    if (v.insert(num).second) {
                        //cout << p.second+1 << " " << num << endl;
                        q.push({{newx,newy},p.second+1});
                    }
                }
            }
        }
        //cout << endl;
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0 ; i < ans.size() ; i++) {
        cout << ans[i] << endl;
    }
}