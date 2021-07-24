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
using namespace std;


void solve() {
    
    int m;
    string s;
    cin >> s;

    int prev = false; // last is one;


    m = s.size();
    long long lenone = 0;
    long long lenzero = 0;
    long long ans = 0;

    for (int i = 0; i < m; i++) {
        if ((s[i] - '0' == !prev) || s[i] == '?') {
            lenone++;
        } else {
            lenone = 0;
        }
        if ((s[i] - '0' == prev) || s[i] == '?') {
            lenzero++;
        } else {
            lenzero = 0;
        }
        ans += max(lenone, lenzero);
        prev = !prev;
    }
    cout << ans << endl;
}

int main(){ 
    int n;
    cin >> n;
    while (n--) solve();
}