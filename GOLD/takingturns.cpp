#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    vector<pair<long long, long long>> dp(n+1, {0,0});

    for (int i = n-1 ; i >= 0 ; i--) {
        pair<long long, long long> p = dp[i+1];
        pair<long long, long long> np = {p.second + v[i], p.first};
        if (p.first > np.first) {
            dp[i] = p;
        } else {
            dp[i] = np;
        }
        //dp[i] = max(v[i+1], {p.second + v[i], p.first});
    }
    cout << dp[0].first << " " << dp[0].second << endl;
}