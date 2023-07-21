#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

#define NMAX 250
#define WMAX 1000

#define infinite 1000000000000000000LL

// The inputs
int weights[NMAX];
int talent[NMAX];

int n;
int w;

// The dp state.
// For 0 <= i < w, this is the maximum adjusted-talent-score achievable
// with weight exactly i.
// For i=w, this is the maximum talent achievable
// with weight AT LEAST w.
long long dp[WMAX + 1];

// Check if a ratio of y/1000 is achievable.
bool doable(int k) {
  for (int i = 0; i <= w; i++) {
    dp[i] = -infinite;
  }
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    long long value = 1000*(long long)talent[i] - k*(long long)weights[i];
    int inc = weights[i];
    for (int j = w; j >= 0; j--) {
      int nxt = min(w, j + inc);
      if (dp[j] != -infinite) {
        if (dp[nxt] < dp[j] + value) {
            dp[nxt] = dp[j] + value;
        }
      }
    }
  }

  return dp[w] >= 0;
}

int main() {
  scanf("%d", &n);
  scanf("%d", &w);
  assert(1 <= n && n <= NMAX);
  assert(1 <= w && w <= WMAX);

  for (int i = 0; i < n; i++) {
    scanf("%d", &weights[i]);
    scanf("%d", &talent[i]);
    assert(1 <= weights[i] && weights[i] <= 1000000);
    assert(1 <= talent[i] && talent[i] <= 1000);
  }

  // Binary search
  // Invariant: lo <= answer < hi
  int lo = 0;
  int hi = (1000 * 250 * 1000) + 1;
  while (hi > lo + 1) {
    int mid = (lo + hi) / 2;
    if (doable(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  printf("%d\n", lo);
}