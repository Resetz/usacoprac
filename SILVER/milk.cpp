/*
ID: vincent97
TASK: milk
LANG: C++                 
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    #ifndef LOCAL
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    #endif

    int n, m;
    cin >> m >> n;
    vector<pair<int,int>> v(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    for (int i = 0 ; i < n; i++) {
        if (v[i].second >= m) {
            ans += v[i].first * m;
            break;
        } else {
            m -= v[i].second;
            ans += v[i].second * v[i].first;
        }
    }
    cout << ans << endl;

}