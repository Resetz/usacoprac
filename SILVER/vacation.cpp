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

int n, k, m;
vector<int> friends;
bool adj[1000][1000];
int visited[1000];
bool v[1000];

void dfs(int cur) {
    if (v[cur]) return;
    v[cur] = true;
    visited[cur]++;
    for (int i = 0 ; i < k ; i++) {
        if (adj[cur][i]) {
            dfs(i);
        }
    }
}
int main() {
    int n;
    cin >> n >> k >> m;
    for (int i = 0; i < n ; i++) {
        int f;
        cin >> f;
        f--;
        friends.push_back(f);
    }
    for (int i =0 ; i < m ; i++) {
        int f;
        int t;
        cin >> f >> t;
        f--;
        t--;
        adj[f][t] = true;
    } 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            v[j] = false;
        }
        dfs(friends[i]);
    }
    int ans = 0;
    for (int i = 0 ; i < k ; i++) {
        if (visited[i] == n) ans++;
    }
    cout << ans << endl;
}