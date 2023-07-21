#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> f(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i] >> t[i];
    }

    vector<int> initial;
    vector<int> to;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < f[i] ; j++) {
            initial.push_back(i);
        }
        for (int j = 0; j  < t[i] ; j++) {
            to.push_back(i);
        }
    }

    int ro,co;
    ro = initial.size();
    co = to.size();
    vector<vector<int>> dp(ro+1, vector<int>(co+1));
    for (int i = 0 ; i <= ro ; i++) {
        dp[i][0] = b*i;
    }
    for (int i = 0;  i <= co ; i++) {
        dp[0][i] = a*i;
    }
    for (int i = 1 ; i <= ro ; i++) {
        for (int j = 1 ; j <= co ; j++) {
            //cout << initial[i-1] << " " << to[j-1] << endl;
            dp[i][j] = min(dp[i-1][j-1]+c*abs(initial[i-1]-to[j-1]), min(dp[i-1][j] + b, dp[i][j-1] + a));
        } 
    }
    cout << dp[ro][co];
    return 0;
}