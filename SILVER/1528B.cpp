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
int dp[1000001] = {0};
int main() {

    //divisor thing
    int n;
    cin >> n;
    

    
    for (int i = 1 ; i <= n ; i++) {
        for (int j = i + i; j <= n ; j+=i) {
            dp[j]++;
        }
    }
    dp[0] = 1;
    long long ans = 1;
    for (int i = 1 ; i <= n ; i ++) {
        dp[i] = (dp[i] + ans) % 998244353;
        ans = (dp[i] + ans) % 998244353;
    }
    cout << dp[n] << endl;
}