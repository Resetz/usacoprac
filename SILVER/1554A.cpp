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

void solve() {
    int n;
    cin >> n;
    long long prev;
    long long next;
    long long ans;

    cin >> prev;
    for (int i = 0; i < n-1; i++) {
        cin >> next;
        if (i == 0) {
            ans = next * prev;
        } else {
            ans = max(ans, next * prev);
        }
        prev = next;
    }
    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}