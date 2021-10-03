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
vector<int> arr;
vector<pair<int,int>> boots;
map<pair<int,int>, int> visited;

int solve(int pos, int boot) {
    if (visited.find({pos, boot}) != visited.end()) return visited[{pos, boot}];
    if (pos == n-1) {
        return 0;
    }
    int ret = -1;
    int first = false;


    for (int i = boot ; i < b; i++) {
        if (boots[i].first < arr[pos]) continue;
        for (int j = (pos + boots[i].second+1); j > pos; j--) {
            if (j >= n) continue;
            if (arr[j] <= boots[i].first) {
                int tot = solve(j,i);
                if (tot == -1) {
                    continue;
                }
                if (first) ret = min(ret, tot + (i-boot));
                else {ret = tot + (i-boot); first = true;}
            }
        }
    }

    visited[{pos, boot}] = ret;
    return ret;
}

int main () {
    cin >> n >> b;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0 ; i < b; i++) {
        int p, d;
        cin >> p >> d;
        boots.push_back({p,d});
    }
    //reverse(all(boots));
    cout << solve(0,0) << endl;
    
    
}