#include <iostream>
#include <vector>

using namespace std;

int main() {

    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 0 ; i < n ;i++) {
        cin >> v[i+1];
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    //vector<vector<bool>> placed(n+1, vector<bool>(n+1, 0));

    int penalty =0;
    for (int i = 1; i <= n ; i++) {
        if (v[i] != i-1) {
            penalty++;
        }
        dp[1][i] = penalty;
    }

    for (int i = 2 ; i <= n ; i++) {
        for (int j = i ; j <= n ; j++) {
            int start = 0;
            int best = n+1;
            for (int k = i ; k <= j ; k++) {
                start = dp[i-1][k-1];
                for (int l = k ; l <= j ; l++) {
                    start += (v[l] != l-k);
                }
                best = min(start, best);
            }
            dp[i][j] = best;
        }
    }
    for (int i = 1; i <= n ; i++) {
        cout << dp[i][n] << endl;
    }
} 