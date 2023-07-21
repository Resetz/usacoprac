#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};

int main() {
    int n, bx, by; 
    cin >> n >> bx >> by;
    
    vector<vector<int>> visited(1001, vector<int>(1001, -1));
    vector<vector<bool>> closed(1001, vector<bool>(1001,false));
    vector<vector<bool>> grid(1001, vector<bool>(1001,true));
    queue<pair<int,int>> removed;
    queue<pair<pair<int,int>,int>> trav;
    
    for (int i = 0 ; i< n ; i++) {
        int r, c;
        cin >> r >> c;
        grid[r][c] = false;
    }

    removed.push_back()
}