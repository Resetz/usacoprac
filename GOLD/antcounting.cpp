#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t,a,s,b;
    cin >> t >> a >> s >> b;
    vector<int> families(t);

    for (int i = 0 ; i < a ; i++) {
        int n;
        cin >> n;
        families[n-1]++;
    }

    //vector<vector<int>> dp(t+1, vector<int>(a, -1));
    vector<long long> dp(a+1, 0);
    vector<long long> cur(a+1, 0);
    dp[0] = 1;
    for (int i = 0; i < t ; i++) {
        for (int j = 0 ; j <= a ; j++) {
            for (int k = 0 ; k <= families[i] ; k++) {
                if (j+k <= a) cur[j + k] += dp[j];
            }
        }   
        dp = cur;
        for (int i = 0 ; i <= a ; i++) {
            cur[i] = 0;
            dp[i] = dp[i] % 1000000;
        }
    }

    long long ans = 0;
    for (int i = s; i <= b; i++) {
        ans += dp[i];
    }
    cout << ans % 1000000 << endl;
}

