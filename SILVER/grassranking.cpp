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

int n, m;
bool reachable[100][100];
bool adj[100][100];
bool visited[100];
set<int> dp[100];
void dfs(int root, int num) {
    reachable[root][num] = true;
    if (visited[num]) {
        for (int i = 0 ; i < n ; i++) {
            reachable[root][i] |= reachable[num][i]; 
        }
        return;
    }
    for (int i = 0; i < n ; i++) {
        if (i != num && adj[num][i]) {
            dfs(root, i);
        }
    }
}

int main() {
    cin >> n;
    cin >> m;
    for (int i = 0 ; i < m ; i++) {   
        int f, t;
        cin >> f >> t;
        f--, t--;
        adj[f][t] = true;
    }    

    bool change = true;
    while (change) {
        change =false;
        for (int i = 0;  i < n ; i++) {
            //dfs is no
            //dfs(i,i);
            for (int j = 0 ; j < n ; j++) {
                if (adj[i][j]) {
                    for (int k = 0 ; k < n ; k++) {
                        bool prev = adj[i][k];
                        adj[i][k] |= adj[i][j] && adj[j][k];
                        if (prev != adj[i][k]) change = true;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int amt = 0;
        int camt = 0;
        for (int j = 0; j < n ; j++) {
            amt += adj[j][i];
            camt += adj[i][j];
        }
        if (amt + camt >= n-1) ans++; 
    }
    cout << ans << endl;
}