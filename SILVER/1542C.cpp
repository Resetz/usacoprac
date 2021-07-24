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
const long long M=(1e9)+7;

/* recursive gcd and similar lcm */
inline long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}
inline long long LCM(long long x,long long y){
	return x/gcd(x,y)*y;
}


void solve() {
    long long n;
    cin >> n;
    long long cur = 1;
    long long ans = 0;
    for (long long i = 1 ; cur <= n ; ++i) {
        cur = LCM(cur, i);
        if (cur > n || cur < 0) {
            break;
        }
        ans += n/cur;
    }
    cout << (ans+n) % M << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}