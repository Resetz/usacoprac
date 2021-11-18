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


vector<int> v;

vector<vector<int>> adj;

vector<int> dist;
map<pair<int,int>, set<int>> m;

bool visited[100000];

void go(int a) {
    for (int i = 0 ; i < 100000 ; i++) {
        visited[i] = false;
    }

    queue<int> q;
    q.push(a);

    while (!q.empty()) {
        int p = q.front();
        q.pop();
        if (visited[p]) continue;
        visited[p] = true;

        for (int i = 0 ; i < adj[p].size() ; i++) {
            m[pair<int,int>(p, adj[p][i])].insert();
            q.push(adj[p][i]);
        }

    }

}

set<int> seen;
void dfs(int a) {
    seen.insert(a);

    for (int i = 0 ; i < adj[a].size() ; i++) {
        m[pair<int,int>(p, adj[a][i])].insert();
        q.push(adj[p][i]);
    }

    seen.remove(a);
}

int main() {
    int n;
    cin >> n;
    v.resize(n);
    adj.resize(n);
    dist.resize(n);

    int total = 0;
    for (int i = 0;  i < n ; i ++) {
        cin >> v[i];
        total += v[i];
    }

    for (int i = 0 ; i < n-1; i++) {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    queue<int> edge;
    for (int i = 0 ; i < n ; i++) {
        if (adj[i].size() == 1) edge.push(i);
    }
    
    while (edge.size() > 0) {
        cout << edge.front() << " ";
        go(edge.front());
        edge.pop();
    }
    cout << endl;

    for (int i = 0 ; i < n ; i++) {
        set<int> sum;
        for (int j = 0 ; j < adj[i].size() ; j++) {
            sum.insert(all(m[make_pair(i, adj[i][j])]));
        }
        int tot = 0;
        set<int>::iterator it;
        for (it = sum.begin() ; it != sum.end() ; it++) {
            tot += v[*it];
        }
        cout << tot << endl;
    }

}