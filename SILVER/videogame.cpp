#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    vector<int> order(m);
    for (int i = 0 ; i < m ; i++) {
        cin >> order[i];
        order[i]--;
    }
    
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> dist[i][j];
        }
    }


    for (int k = 0 ; k < n ; k++) {
        for (int i = 0 ; i < n ; i++) {
            //if (k == i) continue;
            ///if (!dist[i][k]) continue;
            for (int j = 0 ; j < n ; j++) {
                //if (j == i || j == k) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 1 ; i < m ; i++) {
        ans += dist[order[i-1]][order[i]];
        //cout << order[i-1] << " " << order[i] << endl;
    }
    cout << ans << endl;

}