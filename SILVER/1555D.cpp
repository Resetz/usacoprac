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

int main() {
    string s;
    int n;
    int len;


    cin >> len >> n;
    cin >> s;

    vector<vector<int>> dp(6, vector<int>(len+1));
    string perm = "abc";
    int permn = 0;
    do {
        for (int i = 0; i < len; i++) {
            if (perm[i%3] == s[i]) {
                dp[permn][i+1] = dp[permn][i];
            } else {
                dp[permn][i+1] = dp[permn][i] + 1;
            }
        }
        permn++;
    } while (next_permutation(all(perm)));
    while (n--) {
        int from;
        int to;
        cin >> from >> to;
        
        int ans = dp[0][to] - dp[0][from-1];
        for (int i = 1 ; i < 6 ; i++) {
            ans = min(dp[i][to] - dp[i][from-1], ans);
        } 
        cout << ans << endl;
    }
}