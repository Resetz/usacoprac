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
#include <unordered_map>

#define all(n) n.begin(), n.end()
using namespace std;

int x[20];

int N;
int ans = 0;

void dfs(int n) {
    if (n == N) {ans++; return;}
    for ( int i = 0 ; i < N ; i++ ) {
        bool found = true;
        for (int j = 0 ; j < n ; j++) {
            if (abs(n-j) == abs(x[j] - i) || i == x[j]) found = false;
        }
        if (found) {
            x[n] = i;
            dfs(n+1);
        }
    }
}

int main() {
    cin >> N;
    dfs(0);
    cout << ans;
}