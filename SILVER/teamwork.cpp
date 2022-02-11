#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> cows(n);

    vector<int> dp(n+1, 0);
    for (int i = 1 ; i <= n ; i++) {
        cin >> cows[i];
        
        int mv = 0;
        for (int j = 0; j <= min(i, k); j++) {
            mv = max(mv, cows[i-j]);
            dp[i] = max(dp[i], (mv * (j+1) + dp[i-j-1]));
        }
    }
    cout << dp[n] << endl;
}