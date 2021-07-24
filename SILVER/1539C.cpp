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

long long cceil(long long x, long long y) {
    return (x + y - 1) / y;
}
int main() {
    cout << fixed;
    long long n, k, d;
    cin >> n >> k >> d;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector<long long> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(all(arr));
    vector<pair<long long,long long>> groups;
    pair<long long,long long> current;
    current.first = arr[0];
    current.second = arr[0];
    bool pushedlast = false;
    for (int i = 1 ; i < n ; i ++) {
        if (arr[i] - arr[i-1] <= d) {
            current.second = arr[i];
            pushedlast = false;
        } else {
            groups.push_back(current);
            current.first = arr[i];
            current.second = arr[i];
            pushedlast = true;
        }
    }
    
    groups.push_back(current);
    


    // find differences and sort.
    int ans = groups.size();
    vector<pair<long long,long long>> diff;
    for (int i = 1; i < groups.size(); i++) {
        //cout << "{" << groups[i].first << ", " << groups[i].second << "}" << endl;
        diff.push_back(make_pair(groups[i].first - groups[i-1].second, i));
    }
    sort(all(diff));
    for (int i = 0 ; i < diff.size(); i++) {
        if (k > 0 && k >= (cceil((diff[i].first),d)-1)) {
            ans--;
            k -= cceil(diff[i].first,d)-1;
        } else {
            break;
        }
    }
    cout << ans << endl;

}