// time-limit:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    vector<int> v(n, 0);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    vector<int> dp(n+1, 0);
    dp[0] = 0;
    for (int i = 0 ; i < n ; i++) {
        if (dp[i] > dp[i+1]) {
            dp[i+1] = dp[i];
        }
        int s = dp[i];
        int cur = i;


        for (int j = 0 ; j < m && cur < n ; j++) {
            s += v[i+j];
            cur += 2;
            dp[cur] = max(dp[cur], s);
        }
    }
    cout << dp[n] << endl;
}