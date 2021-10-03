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

int nums[20];
int n;

// idk why 3 extra braces but lms wanted that
bool visited[750][750][20] = {{{false}}};

int a = 0;
int b = 0;
int placed = 0;
int ans = 200000;
int total = 0;
int pf[21] = {0};

void dfs(int next) {
    //int i;
    if (visited[a][b][next]) {
        return;
    }
    if (next == n) {
        ans = min(max(max(a,b),total-(a+b)), ans);
        return;
    }
    
    //cout << a << " " << b << endl;

    if (a + nums[next] < 750) {
        a += nums[next];
        visited[a][b][next] = visited[b][a][next] = true;
        dfs(next+1);
        a -= nums[next];
    }

    if (b + nums[next] < 750) {
        b += nums[next];
        visited[a][b][next] = visited[b][a][next] = true;
        dfs(next+1);
        b -= nums[next];
    }

    if (pf[next+1] - a - b < 750) {
        visited[a][b][next] = visited[b][a][next] = true;
        dfs(next+1);
    }
    
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> nums[i];
        pf[i] = total;
        total += nums[i];
    }
    pf[n] = total;
    
    dfs(0);

    cout << ans << endl;
    return 0;
}