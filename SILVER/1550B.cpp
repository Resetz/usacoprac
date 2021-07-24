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
    int n, a, b;
    string s;
    cin >> n >> a >> b;
    cin >> s;

    if (b > 0) {
        cout << (b+a) * n;
    } else {
        int total = 0;
        int prev = s[0];
        int len = 1;
        int len2 = 0;
        for (int i = 1; i < n; i++) {
            if (prev != s[i]) {
                len2++;
            } else {
                if (len2 != 0) {
                    total += a * len2 + b;
                }
                len2 = 0;
                len++;
            }
        }
        if (len2 != 0) {
            total += a * len2 + b;
        }
        total += a * len + b;
        cout << total;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}