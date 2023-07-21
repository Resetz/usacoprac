#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    k /= 2;

    vector<pair<int,int>> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    
    set<pair<int,int>> cur;
    int j = 0;
    bool found = false;
    pair<pair<int,int>,pair<int,int>> res;
    for (int i = 0 ; i < n ; i++) {
        while ( j < n && v[j].first + k < v[i].first ) {
            cur.erase({v[j]});
            j++;
        }

        cur.insert(v[i]);
        set<pair<int,int>>::iterator it = cur.begin();
        for (; it != cur.end(); it++) {
            if (*it == v[i]) continue;
            if (abs(v[i].second - (*it).second) < k) {
                res = pair<pair<int,int>,pair<int,int>>{v[i], *it};
                found = true;
                break;
            }
        }
    }

    long long ans = -1;
    if (found) {
        if (res.first.first > res.second.first) {
            int temp = res.first.first;
            res.first.first = res.second.first;
            res.second.first = temp;
        } 
        if (res.first.second > res.second.second) {
            int temp = res.first.second;
            res.first.second = res.second.second;
            res.second.second = temp;
        }
        //cout << "{" << res.first.first << ", " << res.first.second << "} + {" << res.second.first << ", " << res.second.second << "}" << endl;

        ans = (2*k+res.first.second-res.second.second) * (2*k+res.first.first-res.second.first);
    }
    cout << ans << endl;

}