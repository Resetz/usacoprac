#include <iostream>
#include <string>
#include <cstdio>
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
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_set>

#define all(n) n.begin(), n.end()
using namespace std;
#define int_t int

void solve() {
    int_t n, k;
    cin >> n >> k;

    int_t stop = n - 2 * k;

    vector<long long> arr(n+1);
    int_t len = 0;
    int_t start = -1;
    for (int_t i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    long long ans = INT32_MIN;
    for (long long i = max(stop,1) ; i < n ; i++) {
        for (long long j = i+1 ; j <= n ; j++) {
            ans = max((i*j)-(k*(arr[i]|arr[j])), ans);
        } 
    } 
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}