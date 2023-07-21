#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    freopen("bbreeds.in", "r", stdin);
    freopen("bbreeds.out", "w", stdout);


    string s;
    cin >> s;
    int n = s.size();

    if (n%2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> dp(n/2+1, vector<int>(n/2+1, 0));
    vector<vector<int>> cur(n/2+1, vector<int>(n/2+1, 0));

    int tl = 0;
    int tr = 0;
    dp[0][0] = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <= n/2 ; j++) {
            for (int k = 0 ; k <= j ; k++) {
                cur[j][k] = 0;
            }
        }
        for (int j = 0 ; j < n/2 ; j++) {
            for (int k = 0 ; k <= j ; k++) {
                // j is the number of Gs
                // k is the number of left parentheses (in gs) "("
                int gl = k;
                int gr = j-gl;
                int rl = tl-k;
                int rr = tr-gr;
                //cout << i << ": " << "(" << j << " - " << dp[j][k] << ")" << gl << " " << gr << ", " << rl << " " << rr << endl;
                //ensure that gr is <= gl
                if (s[i] == '(') {
                    cur[j+1][gl+1] += dp[j][k];
                    cur[j+1][gl+1] %= 2012;
                    cur[j][gl] += dp[j][k];
                    cur[j][gl] %= 2012;
                } else {
                    if (gr < gl) {
                        cur[j+1][gl] += dp[j][k];
                        cur[j+1][gl] %= 2012;
                    } 
                    //if (k <= n/2) {
                    if (rr < rl) {
                        cur[j][gl] += dp[j][k];
                        cur[j][gl] %= 2012;
                    }
                    //}
                }
            }
        }
        if (s[i] == '(') {
            tl++;
        } else {
            tr++;
        }
        dp = cur;
    }
    int ans = 0;
    for (int i = 0 ; i <= n/2 ; i+=2) {
        ans = (ans + dp[i][i/2]) % 2012;
    }
    cout << ans*2%2012 << endl;
}