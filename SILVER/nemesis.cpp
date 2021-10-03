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

int dist[1000];
bool adj[1000][1000];

queue<pair<int,int>> q;

int n, m;
void dfs(int num, int cur) {
    cout << num << " " << cur << endl;
    dist[num] = cur;
    for (int i = 0 ; i < n ; i++) {
        if (adj[num][i] && dist[i] == -1) {
            dfs(i, cur+1);
        }
    }
}

int main() {
    cin >> n >> m;


    for (int i = 0 ; i < n ; i ++) {
        dist[i] = -1;
        for (int j = 0 ; j < n ;j ++) {
            adj[i][j] = false;
        }
    }

    for (int i = 0 ; i < m ; i++) {
        int f, t;
        cin >> f >> t;

        f--; t--;
        adj[f][t] = true;
        adj[t][f] = true;
    }


    q.push(make_pair(0,0));
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        int num = p.first;
        int cur = p.second;

        if (dist[num] != -1) {
            continue;
        }
        dist[num] = cur;
        for (int i = 0 ; i < n ; i++) {
            if (adj[num][i] && dist[i] == -1) {
                q.push(make_pair(i, cur+1));
            }
        }
    }

    int max = 0;
    int ans = 0;
    int ansn = 0;
    for (int i = 0 ; i < n; i ++) {
        if (dist[i] >= max) {
            ans++;
            if (dist[i] > max) {
                max = dist[i];
                ans = 1;
                ansn = i;
            }
        }
    }
    cout << ansn+1 << " " << max << " " << ans << endl;
}