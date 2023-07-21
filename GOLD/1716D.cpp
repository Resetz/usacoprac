#include <iostream>
#include <vector>

using namespace std;

const long long mod = 998244353;

int main() {
    int a, b;
    cin >> a >> b;

    vector<long long> dp(a+1, 0);
    vector<long long> cur(a+1, 0);
    vector<long long> ans(a+1, 0);

    dp[0] = 1;
    for (int i = 0 ; i <= 500 ; i++) {
        for (int j = 0 ;j <= a-(b+i); j++) {
            int go = b+i;
            while (j+go <= a) {
                cur[j+go] = (cur[j+go] + dp[j]) % mod;
                go += b+i;
            }
        }
        for (int j = 0 ; j <= a ; j++) {
            ans[j] = (dp[j] + ans[j]) % mod;
        }
        dp = cur;
        for (int j = 0 ; j <= a ; j++) {
            cur[j] = 0;
        }
    }

    for (int i = 1 ; i <= a ; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}