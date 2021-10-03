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

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n, make_pair(0,0));
    vector<pair<int,int>> b(n, make_pair(0,0));
    for (int i = 0; i < n ; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n ; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    if (a[0] < b[0]) {
        cout << 0 << endl;
        return;
    }

    sort(all(b));
    sort(all(a));
    
    int ans = n;

    int least = n;

    for (int i = 0; i < n; i++) {
        least = min(a[i].second,least);
        ans = min(b[i].second + least, ans);
    }
    cout << ans << endl;


}

int main() {
    int n;
    cin >> n;
    while(n--) solve();
}