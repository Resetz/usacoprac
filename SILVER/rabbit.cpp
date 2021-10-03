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

vector<pair<int,int>> adj[5000];
int n;
int q;
int ans;

bool visited[5000];
int num;

void dfs(int root) {
    visited[root] = true;
    for (int i = 0 ; i < adj[root].size() ; i++) {
        if (visited[adj[root][i].first]) continue;
        if (adj[root][i].second >= num) {
            ans++;
            visited[adj[root][i].first] = true;
            dfs(adj[root][i].first);
        } 
    } 
    visited[root] = false;
}

void solve() {
    int b;
    cin >> num >> b;
    ans = 0;
    dfs(b-1);
    cout << ans << endl;
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int f,t,d;
        cin >> f >> t >> d;
        f--;
        t--;
        adj[f].push_back(make_pair(t,d));
        adj[t].push_back(make_pair(f,d));
    }
    
    while (q--) solve();
}