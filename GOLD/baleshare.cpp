#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
        sum += v[i];
    }

    vector<vector<bool>> vis(801, vector<bool>(801));

    vis[0][0] = true;
    int ans = INT_MAX;
    for (int it = 0 ; it < n ; it++) {
        for (int i = 800 ; i >= 0 ; i--) {
            for (int j = 800 ; j >= 0 ; j--) {
                //out << i << " " << j << endl;
                if (vis[i][j]) {
                    if (i + v[it] < 800) {
                        vis[i+v[it]][j] = true;
                    }
                    if (j + v[it] < 800) {
                        vis[i][j+v[it]] = true;
                    }
                    
                }
            }
        }
    }
    for (int i = 0 ; i < 801 ; i++) for (int j = 0 ; j < 801 ; j++) {
        if (vis[i][j]) {
            ans = min(ans, max(i, max(j, sum-(i+j))));
            //cout << i << " " << j << " " << (sum - (i+j)) << endl;
        }
    }
    cout << ans << endl;
}