#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>

#define all(n) n.begin(), n.end()
using namespace std;

unsigned long long dp[51];

void solve() {
    int n, k;
    cin >> n >> k;

    unsigned long long ans = 0;
    unsigned long long overflow = 0;
    unsigned long long allowed_next = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] < k) ans++;
        else {
            unsigned long long amt = dp[i] - overflow;
            allowed_next = (amt / k) * k;
            if (allowed_next != dp[i]) {
                overflow = (allowed_next + k) - amt;
                ans++;
            }
            ans += amt / k;
        }
    }
    cout << ans << endl;
}

int main() {
    unsigned long long pow2 = 1;
    for (int i = 0 ; i < 51 ; i++) {
        dp[i] = pow2;
        pow2 *= 2;
    }

    int n;
    cin >> n;
    while (n--) solve();
}