#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
int mod = 2014;
int hashmod = 1e9+7;

using namespace std;

int main() {
    #define int long long
    string s;
    cin >> s;

    int n = s.size();

    vector<int> hash(n+1, 0);
    vector<int> pow(n+1, 1);
    long long cur = 1;
    for (int i = 1 ; i <= n ; i++) {
        hash[i] = (hash[i-1] + s[i-1] * cur) % hashmod;
        cur = cur * 31 % hashmod;
        pow[i] = cur % hashmod;
    }

    vector<vector<int>> dp(n+1, vector<int>(n, 0));
    // length, leftchar
    dp[n][0] = 1;
    int ans = 0;
    for (int i = n ; i >= 2 ; i--) {
        for (int pos = 0 ; pos <= n-i ; pos++) {
            if (i != n) {
                ans = (dp[i][pos] + ans) % mod;
                //cout << "dp[" << i << "][" << pos << "] = " << dp[i][pos] << endl;
            }
            int endpos = pos + i;
            for (int j = 1 ; j <= (i-1)/2; j++) {
                //cout << j << ": ";
                int lefthasha = (hash[pos+j] - hash[pos] + hashmod) % hashmod;
                int lefthashb = (hash[pos+j+j] - hash[pos+j] + hashmod) % hashmod;
                int righthasha = (hash[endpos] - hash[endpos-j] + hashmod) % hashmod;
                int righthashb = (hash[endpos-j] - hash[endpos-j-j] + hashmod) % hashmod;
                //cout << lefthasha * pow[i-j] % hashmod << " " << righthashb << endl;

                if (lefthasha * pow[j] % hashmod == lefthashb) {
                    //cout << "a ";
                    dp[i-j][pos+j] = (dp[i-j][pos+j] + dp[i][pos]) % mod;
                }
                if (lefthasha * pow[i-j] % hashmod == righthasha) {
                    //cout << "b ";
                    dp[i-j][pos+j] = (dp[i-j][pos+j] + dp[i][pos]) % mod;
                    dp[i-j][pos] = (dp[i-j][pos] + dp[i][pos]) % mod;
                }
                if (righthasha == righthashb * pow[j] % hashmod) {
                    //cout << "c ";
                    dp[i-j][pos] = (dp[i-j][pos] + dp[i][pos]) % mod;
                }
                //cout << endl;
            }
        }
        int a;
        //cin >> a;
    }
    cout << ans << endl;
}