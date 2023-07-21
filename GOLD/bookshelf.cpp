#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int l;
int n;
vector<pair<int,int>> v;
int main() {
    cin >> n >> l;

    v.resize(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }

    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for (int i = 0 ; i < n ; i++) {
        int curlen = 0;
        int height = 0;
        for (int j = i ; j < n ; j++) {
            curlen += v[j].second;
            if (curlen > l) break;
            height = max(height, v[j].first);
            dp[j+1] = min(dp[j+1], dp[i] + height);
        }
    }
    cout << dp[n] << endl;

}