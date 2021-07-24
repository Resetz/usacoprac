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

int n;

map<int, vector<long long>> prefix;

void solve() {
    int len;
    cin >> len;
    
    long long arr[100000];
    for (int i = 0 ; i < len; i++) {
        cin >> arr[i];
    }

    vector<long long> dp(len+1, 0);

    map<long long, long long> total;

    long long ans =0 ;
    for (int i = 0 ; i < len; i++) {
        if (i > 0) dp[i] = dp[i-1]; //dp[i-1] doesn't exist for i == 0

        if (total[arr[i]] /*if it exists*/ ) {
            dp[i] += total[arr[i]];
        }
        total[arr[i]] += i + 1;
        //an additional i subarrays now have an additional arr[i] which means that i+1 more valid pairs exist.
        ans += dp[i];
    }
    cout << ans << endl;
}
int main() {
    cin >> n;
    while (n--) solve();
}