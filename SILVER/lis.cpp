// longest increasing subsequence
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> dp(n+1);
    vector<int> v(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
        dp[i] = 0;
    }

    int ans = 0;
    for (int i = n-1; i >= 0 ; i--) {
        int highest = 0;
        for (int j = i+1 ; j < n ; j++) {
            if (v[i] < v[j]) {
                highest = max(dp[j], highest);
            }
        }
        dp[i] = highest+1;
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
    
}