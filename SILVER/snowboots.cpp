#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;

vector<unsigned long long> v;
vector<pair<unsigned long long, unsigned long long>> boots;
vector<vector<bool>> dp;

int ans = INT_MAX;
void dfs(int pos, int boot) {
    if (pos >= n || boot >= m) {
        return;
    }
    if (dp[pos][boot]) {
        return;
    }
    dp[pos][boot] = true;

    if (pos == n-1) {
        ans = min(ans, boot);
        return;
    }

    int ret = INT_MAX;
    if (v[pos] > boots[boot].first) {
        return;
    }
    for (int i = pos+1 ; i <= pos+boots[boot].second; i++) {
        dfs(i, boot);
    }
    for (int i = boot+1 ; i < m ; i++) {
        dfs(pos, i);
    }
}

int main() {

    freopen("snowboots.out", "w", stdout);
    freopen("snowboots.in", "r", stdin);

    cin >> n >> m;

    v.resize(n);
    boots.resize(m);

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }
    for (int i = 0 ; i < m ; i++) {
        cin >> boots[i].first >> boots[i].second;
    }

    dp.resize(n, vector<bool>(m, false)); 

    dfs(0,0);
    cout << ans << endl;
}