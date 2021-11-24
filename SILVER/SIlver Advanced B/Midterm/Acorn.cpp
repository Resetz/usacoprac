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
#include <climits>
#include <iomanip>

using namespace std;

int x[100000];
int y[100000];
bool v[100000];
vector<int> adj[100000];

int main() {
    int n, m;
    int ans = INT_MAX;
    cin >> n >> m;

    for (int i = 0 ; i < n ; i ++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0 ; i < m ; i++) {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
    for (int i = 0; i < m ; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    int found = 0;
    queue<int> q;
    while (found < n) {
        
        int next = 0;
        for (next = 0; next < n ; next++) {
            if (!v[next]) break;
        }
        int bot = INT_MAX;
        int top = 0;
        int left = INT_MAX;
        int right = 0;

        q.push(next);
        
        while (!q.empty()) {
            
            int num = q.front();
            q.pop();
            
            if (v[num]) continue;
            v[num] = true;
            found++;
            
            bot = min(bot, y[num]);
            top = max(top, y[num]);
            left = min(left, x[num]);
            right = max(right, x[num]);
            
            for (int i = 0 ; i < adj[num].size(); i++) {
                int k = adj[num][i];
                q.push(k);
            }
            
        }
        ans = min((top - bot) + (right - left), ans);
    }
    cout << 2 * ans << endl;
    
    
}