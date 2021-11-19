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

int arr[100000]; // position i contains arr[i]
vector<vector<pair<long long, long long>>> wormholes; // wormholes
int n, m;

bool check(long long k) {

    bool visited[100000] = {false};
    int found = 0; // store the amount of cows we've visited;
    while (found != n) { // stop when we visit all cows.
        queue<long long> q; // queue for bfs

        set<long long> v; // positions visited
        set<long long> g; // cows seen
        int next = -1;
        
        // find the next unvisited cow
        for (next = 0 ; next < n ; next++) {
            if (!visited[next]) {
                //found it
                break;
            }
        }
        
        // start dfs from this node
        q.push(next);
        while (!q.empty()) {
            // regular bfs stuff
            long long pos = q.front();
            q.pop();
            if ( visited[pos] ) continue;
            visited[pos] = true;

            found++;
            v.insert(pos); // add the position
            g.insert(arr[pos]); // add the cow

            // more regular dfs
            for (int i = 0 ; i < wormholes[pos].size(); i++) {
                if (wormholes[pos][i].second >= k) { 
                    q.push(wormholes[pos][i].first);
                }
            }
        }   

        // if the cows visited are not equal to the positions at any point.
        if (v != g) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;

    wormholes.resize(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i];
        arr[i]--;
    }

    // check if there is a need to use a any wormhole
    if (is_sorted(arr, arr + n)) {
        cout << -1 << endl;
        return 0;   
    }
    

    vector<long long> c; // array to store costs; more effective to b search over options rather than all numbers.
    for (int i = 0 ; i < m ; i++) {
        long long f, t, s;
        cin >> f >> t >> s;
        c.push_back(s);
        f--; t--;
        wormholes[f].push_back({t, s});
        wormholes[t].push_back({f, s});
    }
    sort(all(c));


    // binary search
    long long high = c.size(), low = 0, mid;
    long long ans = 0;
    while (high > low) {
        mid = (high + low)/2;
        bool res = check(c[mid]);
        if (res) {
            ans = c[mid];
            low = mid+1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
}