#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<long long,long long>> v(n);
    for (int i = 0 ; i < n; i ++) {
        cin >> v[i].first >> v[i].second;
    }

    //cout << endl;
    long long r = 0;
    long long cur = v[0].first;
    multiset<long long, std::greater<long long>> highest;
    long long h = 0;
    highest.insert(v[0].second);
    long long ans = INT_MAX;
    for (int l = 0 ; l < n ; l++) {
        /*if ( r < l ) {
            r++;
            cur = v[l].first;
            highest.clear();
            highest.insert(v[l].second);
        }*/
        while (cur < m && r < n) {
            r++;
            cur += v[r].first;
            highest.insert(v[r].second);
        }
        if (r >= n) break;
        ans = min(ans, *highest.begin());
        cur -= v[l].first;
        highest.erase(highest.lower_bound(v[l].second));

        //cout << r <<  " " << l << endl;
    }
    //ans = min(ans, *max_element(highest.begin(), highest.end()));
    cout << ans << endl;
}