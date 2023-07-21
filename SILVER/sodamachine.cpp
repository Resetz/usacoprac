#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<unsigned long long, int>> v(n*2);

    for (int i = 0 ; i < n ; i++) {
        unsigned long long a,b;
        cin >> a >> b;
        v[i*2] = {a*2,1};
        v[i*2+1] = {b*2+1,-1};
    }

    sort(v.begin(),v.end());

    int cur = 0;
    int ans = 0;
    int prev =0;
    for (int i = 0 ; i < n*2 ; i++) {
        if (prev != v[i].first) {
            //cout << cur << endl;
            ans = max(cur,ans);
        }
        cur += v[i].second;
        prev = v[i].first;
    }
    cout << ans << endl;
}