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

#define all(n) n.begin(), n.end()
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> positions;
    vector<int> empty;

    int i;
    for (int i = 0 ; i < n ; i++) {
        int num = 0;
        cin >> num;
        if (num == 1) {
            positions.push_back(i);
        } else {
            empty.push_back(i);
        }
    }
    sort(all(positions));
    sort(all(empty));

    int k = positions.size();
    vector<vector<int>> dp(positions.size()+1, vector<int>(empty.size()+1, INT_MAX));
    dp[0][0] = 0;

    for(i=0;i<=(int)empty.size();++i)
		dp[0][i]=0;
 

    for (int i = 1 ; i <= (int)positions.size(); ++i) {
        for (int j = i; j <= (int)empty.size(); ++j) {
            dp[i][j] = min(dp[i][j-1],dp[i-1][j-1] + abs(positions[i-1]-empty[j-1]));
        }
    }
    cout << dp[(int)positions.size()][(int)empty.size()] << endl;



}