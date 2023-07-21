#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> cows(n);
    vector<int> u(k);
    for (int i = 0 ; i < n ; i++) {
        cin >> cows[i];
    } 
    for (int i = 0 ; i < k ; i++) {
        cin >> u[i];
    }

    sort(cows.begin(), cows.end());
    for (int i = k-2; i >= 0 ; i--) {
        u[i] = min(u[i], u[i+1]);
    }

    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = i ; j <= n ; j++) {
            if (cows[j-1] - cows[i-1] < k) {
                dp[j] = min(dp[j], u[cows[j-1] - cows[i-1]] + dp[i-1]);
            } else {
                continue;
            }
        }
    }
    cout << dp[n] << endl;
}