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
    vector<int> top(n, 0), bot(n, 0);

    int sumtop = 0;
    int sumbot = 0;
    for (int i = 0; i < n; i++) {
        cin >> top[i];
        if (i != 0) {
            sumtop += top[i];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> bot[i];
    }
    
    if (n == 1) {cout << 0 << endl; return;}
    int ans = INT_MAX;
    for (int i = 1 ; i < n ; i++) {
        ans = min(max(sumtop,sumbot),ans);
        sumbot += bot[i-1];
        sumtop -= top[i];
    }
    ans = min(max(sumtop,sumbot),ans);
    cout << ans << endl;   
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}