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
vector<vector<pair<long long, long long>>> tps;
int n, m;

bool check(long long k) {
    bool visited[100000] = {false};
    int found = 0;
    while (found != n) {
        queue<long long> q;
        set<long long> v;
        set<long long> g;
        int next = -1;
        for (next = 0 ; next < n ; next++) {
            if (!visited[next]) {
                break;
            }
        }
        q.push(next);
        while (!q.empty()) {
            long long f = q.front();
            q.pop();
            if ( visited[f] ) continue;
            found++;
            v.insert(f);
            g.insert(arr[f]);
            visited[f] = true;
            for (int i = 0 ; i < tps[f].size(); i++) {
                if (tps[f][i].second >= k) { 
                    q.push(tps[f][i].first);
                }
            }
        }
        //if (v.empty() || g.empty()) { return true; }
        if (v != g) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;

    tps.resize(n);
    //int last = 0;
    //bool sorted = true;
    for (int i = 0 ; i < n ; i++) {
        
        
        cin >> arr[i];
        arr[i]--;
        // which one of these is it?
        /*
        int num;
        cin >> num;
        num--;
        arr[num] = i;
        */
    }
    if (is_sorted(arr, arr + n)) {
        cout << -1 << endl;
        return 0;   
    }
    

    vector<long long> c;
    for (int i = 0 ; i < m ; i++) {
        long long f, t, s;
        cin >> f >> t >> s;
        c.push_back(s);
        f--; t--;
        tps[f].push_back({t, s});
        tps[t].push_back({f, s});
    }
    sort(all(c));

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