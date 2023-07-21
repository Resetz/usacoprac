#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> v(n);

    for (int i = 0; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    vector<vector<int>> dp(n, vector<int>(n, 0));

    //cout << endl;
    for (int i = 0 ; i < n ; i++) {
        dp[i][i] = v[i].first;
        //cout << v[i].first << " " << v[i].second << endl;
    }

    for (int i = n-1; i >= 0 ; i--) {
        for (int j = 0 ; j < i ; j++) { // left
            int best = v[j].second + v[i].second;
            for (int k = i+1 ; k < n ; k++) {
                //cout << i << " " << j << " " << k << endl;
                if (v[i].first - v[j].first <= v[k].first - v[i].first) {
                    //calc
                    //cout << j << " " << i << " " << k << " | " << dp[i][k] << endl;
                    best = max(best, v[j].second + dp[i][k]);
                }
            }
            //cout << endl;
            //cout << j << " " << i << " = " << best << endl;
            //cout << endl;
            
            dp[j][i] = best;
        }
    }
    int ans = 0;
    for (int i = 0; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    reverse(v.begin(), v.end());
    for (int i = 0 ; i < n ; i++) {
        v[i].first *= -1;
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            dp[i][j] = 0;
            if (i == j) {
                dp[i][j] = v[i].first;
            }
        }
    }


    for (int i = n-1; i >= 0 ; i--) {
        for (int j = 0 ; j < i ; j++) { // left
            int best = v[j].second + v[i].second;
            for (int k = i+1 ; k < n ; k++) {
                //cout << i << " " << j << " " << k << endl;
                if (v[i].first - v[j].first <= v[k].first - v[i].first) {
                    //calc
                    //cout << j << " " << i << " " << k << " | " << dp[i][k] << endl;
                    best = max(best, v[j].second + dp[i][k]);
                }
            }
            //cout << endl;
            //cout << j << " " << i << " = " << best << endl;
            //cout << endl;
            
            dp[j][i] = best;
        }
    }
    for (int i = 0; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
}            