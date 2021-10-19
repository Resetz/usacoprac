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
int n, b;
int arr[250];
int ans = 250;
vector<pair<int,int>> boots;
map<pair<int,int>, int> visited;

int solve(int pos, int boot, int cur) {
    if (cur > ans) return -1;
    if (boots[boot].first < arr[pos]) return -1;
    pair<int, int> p = make_pair(pos, boot);
    if (visited.find(p) != visited.end()) return visited[p];
    if (pos == n-1) {
        ans = min(ans, cur);
        return 0;
    }
    int ret = 250;
    bool first = false;


    for (int i = boot ; i < b; i++) {
        if (boots[i].first < arr[pos]) continue;
        if (boots[i].first < boots[boot].first && boots[i].second < boots[boot].second) continue;
        for (int j = min(n-1, pos + boots[i].second); j > pos; j--) {
            if (arr[j] <= boots[i].first) {
                int tot = solve(j,i,cur+(i-boot));
                if (tot == -1) {
                    continue;
                }
                ret = min(ret, tot+(i-boot));
            }
        }
    }

    visited[p] = ret == 250 ? -1 : ret;
    return ret == 250 ? -1 : ret;
}

int main () {
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    boots.resize(n);
    for (int i = 0 ; i < b; i++) {
        int p, d;
        cin >> p >> d;
        boots[i] = make_pair(p, d);
    }
    //reverse(all(boots));
    cout << solve(0,0,0) << endl;
    
    
}