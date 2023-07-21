#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int i = 0 ; i < n ;i++) {
        //row wise;
        //count initial;
        int cur_sum = 0;
        for (int j = 0 ; j <= k*2 ; j++) {
            int row = i + j-k;
            if (row < 0 || row >= n) continue;
            if ( j < k ) {
                for (int l = 0; l < j+1 ; l++) {
                    cur_sum += grid[row+j][l];
                }
            } else {
                for (int l = 0; l < k-j+1 ; l++) {
                    cur_sum += grid[row+j][l];
                }
            }
        }
        for (int j = 0 ; j < n ;j++) {
            //center at i,j
            ans = max(ans, cur_sum);
            //transition
            //removal;

            int posx = i;
            int posy = i-j;
        }   
    }
}