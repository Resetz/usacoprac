#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<pair<int,int>> v;
int n, w;
int go(int k) {
    vector<long long> dp(w+1, LLONG_MIN);

    dp[0] = 0;
    
    for (int i = 0 ; i < n ; i++) {
        long long cur = 1000 * (long long) v[i].second - k*(long long)v[i].first;
        int inc = v[i].first;
        for (int j = w ; j >= 0 ; j--) {
            int nxt = min(w, j + inc);
            if (dp[j] != LLONG_MIN) {
                if (dp[nxt] < dp[j] + cur) {
                    dp[nxt] = dp[j] + cur;
                }
                //dp[nxt] = max(dp[nxt], dp[j]+cur);
            }
        }
    }
    return dp[w] >= 0;
}

int main() {
    cin >> n >> w;

    v.resize(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }

    int lo = 0;
  int hi = (1000 * 250 * 1000) + 1;
  while (hi > lo + 1) {
    int mid = (lo + hi) / 2;
    if (go(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  printf("%d\n", lo);
}