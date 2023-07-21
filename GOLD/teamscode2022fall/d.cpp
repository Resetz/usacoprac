#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n,m;
int get(vector<vector<int>> pf, int i, int j, int k, int l) {
    //cout << i << " " << j << " " << k << " " << l << endl << endl;
    if (i < 0 || i >= n || j >= n || j < 0 || k < 0 || l < 0 || k >= n || l >= m) return 0;
    return pf[k+1][l+1] - pf[i][l+1] - pf[k+1][j] + pf[i][j];
}
int main() {
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    vector<vector<int>> pf(n+1, vector<int>(m+1));
    pair<int,int> neg;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> grid[i][j];
            if (grid[i][j] < 0) neg = {i,j};
            pf[i+1][j+1] = grid[i][j] + pf[i+1][j] + pf[i][j+1] - pf[i][j];
        }
    }

    //cout << "here" << endl;
    int ans = 0;
    ans = max(ans, get(pf,0,0,n-1,neg.second-1));
    ans = max(ans, get(pf,neg.second+1,0,n-1,m-1));
    ans = max(ans, get(pf,0,0,neg.first-1,m-1));
    ans = max(ans, get(pf,0,neg.first+1,n-1,m-1));
    ans = max(ans, get(pf,0,0,n-1,m-1));
    cout << ans << endl;
    
}