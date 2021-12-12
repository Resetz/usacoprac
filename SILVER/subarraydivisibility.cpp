// cses: https://cses.fi/problemset/task/1662
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> pf(n+1);

    vector<long long> dp(n);
    long long cur = 0;
    dp[0]++;
    for (long long i = 0 ; i < n ; i++) {
        long long k;
        cin >> k;
        cur += k;
        dp[(cur % n + n) % n]++;
    }
    long long ans = 0;
    for (long long i = 0 ; i < n ; i++) {
        ans += (dp[i] * (dp[i] - 1)) / 2ull;
    }
    cout << ans << endl;
}