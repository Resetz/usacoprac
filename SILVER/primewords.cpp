#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    #define int unsigned long long
    int MOD = 1e9+7;
    int n;
    cin >> n;

    vector<int> cur(1000);
    vector<int> dp(1000);

    set<int> primes{2,3,5,7, 11, 13, 17, 19, 23, 29, 31};
    for (int i = 0 ; i < 10 ; i++) {
        for (int j = 0 ; j < 10 ; j++) {
            for (int k = 0 ; k < 10 ; k++) {
                for (int m = 0 ; m < 10 ; m++) {
                    if (primes.find(i+j+k+m) != primes.end()) {
                        dp[j*100+k*10+m] += 1;
                    }
                }
            }
        }
    }
    for (int i = 3 ; i < n-1; i++) {
        for (int j = 0; j < 1000 ; j++) {
            if (dp[j] != 0){
                int sum = j%10 + (j/10)%10 + (j/100)%10;
                int newn = (j - ((j/100)%10)*100)*10;
                for (int k = 0 ; k < 10 ; k++) {
                    if (primes.find(sum + k) != primes.end()) {
                        cur[newn+k] = (cur[newn+k] + dp[j]) % MOD;
                    }
                }
            }
        }
        dp = cur;
        for (int j = 0 ; j < 1000 ; j++) cur[j] = 0;
    }
    int ans = 0;
    for (int i = 0 ; i < 1000 ; i++) {
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << endl;
}