#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> adj;

unsigned long long dp[100001];
int main() {

    unsigned long long n;
    cin >> n;

    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        unsigned long long f, t;
        cin >> f >> t;
        f--; t--;   
        dp[f]++;
        dp[t]++;
    }


    unsigned long long ans = n-1;
    for (int i = 0 ; i < n ; i++) {
        int spread = 0;
        unsigned long long cow = 1;
        int target = dp[i];
        if (i != 0) {
            target--;
        }
        while ( cow <= target ) {
            spread++;
            cow *= 2ull;
        }
        ans += spread;
    }
    cout << ans << endl;

}