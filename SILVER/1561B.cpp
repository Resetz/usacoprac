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

bool check(vector<pair<long long,long long>> p, long long n, long long checking) {
    for (int i = 0; i < n ; i++) {
        //cout << checking << "(" << p[i].first << ", " << p[i].second << ")" << endl;
        if (checking >= p[i].first) checking += p[i].second;
        else return false;
    }
    return true;
}

void solve() {
    long long n;
    cin >> n;
    vector<pair<long long,long long>> p;

    for (int i = 0 ; i < n ; i++) {
        long long num;
        cin >> num;
        long long maxi = 0;
        for (int j = 0 ; j < num ; j++) {
            long long k;
            cin >> k;
            maxi = max(k-j+1, maxi);
        }
        p.push_back(make_pair(maxi, num));
    }
    sort(all(p));

    long long high = 10e9;
    long long low = 0;
    long long ans;
    while (high >= low) {
        long long mid = (high + low)/2;
        bool c = check(p, n, mid);
        //cout << endl;
        if (c) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    cout << ans << endl;
}
int main() {
    int n;
    cin >> n;
    while (n--) solve();
}