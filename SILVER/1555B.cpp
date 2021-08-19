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
    int w, l;
    cin >> w >> l;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w1, w2, l1, l2;
    cin >> w1 >> l1;
    w2 = abs(x2 - x1);
    l2 = abs(y2 - y1);

    int topx = max(x1, x2);
    int topy = max(y1, y2);
    int botx = min(x1, x2);
    int boty = min(y1, y2);

    int ans = -1;
    bool did_first = false;
    if (l2 + l1 <= l) {
        did_first = true;
        int n;
        n = max(l - topy, boty);
        ans = max(l1 - n, 0); 
    } if (w1 + w2 <= w) {
        int n;
        n = max(w - topx, botx);
        if (did_first) {
            ans = min(max(w1 - n, 0), ans);
        } else {
            ans = max(w1 - n, 0);
        }
    }
    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}