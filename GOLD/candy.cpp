#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    int n,m,f,bonus;
    cin >> n >> m >> f >> bonus;

    vector<int> v(m);
    for (int i = 0 ; i < m ; i++) cin >> v[i];

    vector<int> fnums(f);
    vector<int> fav(n+100, 0);
    for (int i = 0 ; i < f ; i++) {
        cin >> fnums[i];
        fav[fnums[i]] = true;
    }

    vector<int> dp(n+100, -1);
    vector<int> cur(n+100, -1);
    vector<int> vis(n+100, 0);
    dp[n] = 0;

    int ans = 0;
    int highMax = n;
    while (highMax != 0) {
        int prev = highMax;
        highMax = 0;
        for (int i = prev ; i >= 0 ; i--) {
            if (dp[i] == -1) continue;
            for (int j = 0 ; j < m ; j++) {
                if (i-v[j] < 0) continue;
                if (dp[i-v[j]] < dp[i]+v[j]) {

                    dp[i-v[j]] = max(dp[i-v[j]], dp[i]+v[j]);
                }
            }
            if (fav[i]) {
                vis[i]++;
                if (vis[i] == f+1) {
                    cout << -1 << endl;
                    return 0;
                }
                highMax = max(i+bonus, highMax);
                cur[i+bonus] = max(cur[i+bonus], dp[i]);
                //cout << "new highmax " << i+bonus << endl; 
            }
        }

        for (int i = 0 ; i < n+100 ; i++) {
            ans = max(ans, dp[i]);
        }
        dp = cur;
        for (int i = 0 ; i < n+100 ; i++) {
            cur[i] = -1;
        }
    }
    for (int i = 0 ; i < n+100 ; i++) {
        ans = max(cur[i], ans);
    }
    cout << ans << endl;
    //cout << " ? " << endl;
}