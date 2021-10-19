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

using namespace std;

int nums[2200];

unsigned long long ans = 0;

void dfs(int from, int to) {
    if (to - from == 1) {
        ans += (to+1) * (from+1);
        //cout << to + 1 << " " << from + 1 << endl;
        return;
    } else if ( (to+1) == (from+1) ) {
        return;
    } 

    dfs(from, (from + to) / 2);
    dfs((from + to) / 2 + 1, to);
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) nums[i] = i+1;
    dfs(0, n - 1);
    cout << ans << endl;
}