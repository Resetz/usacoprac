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
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define all(n) n.begin(), n.end()
using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    vector<pair<int,int>> pairs;
    for (int i = 0; i < k; i++) {
        int first, second;
        cin >> first >> second;
        if (second > first) {
            pairs.push_back(make_pair(second, first));
        } else {
            pairs.push_back(make_pair(first, second));
        }
    }
    
    sort(all(pairs));
    int last = 0;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (pairs[i].second >= last) {
            ans++;
            last= pairs[i].first;
        } 
    }
    cout << ans;
}