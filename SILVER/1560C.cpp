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

vector<unsigned long long> dp(32000);

void solve() {
    unsigned long long n;
    cin >> n;
    if (n == 1) {
        cout << "1 1" << endl;
        return;
    }
    unsigned long long l = 0;
    while (dp[l] < n) {l++;}
    unsigned long long mid = dp[l] - l + 1;
    if (n == mid) {
        cout << l << " " << l << endl;
    } else if (n > mid) {
        cout << l << " " << (l) - (n - mid) << endl;
    } else {
        cout << (l) - (mid - n) << " " << l << endl;
    }
    
}

int main() {
    unsigned long long i = 0;
    while (i < 32000) {
        dp[i] = i*i;
        i++;
    }

    int n;
    cin >> n;
    while (n--) solve();    
}