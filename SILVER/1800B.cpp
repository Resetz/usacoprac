#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n,b;
    cin >> n >> b;
    string v;
    cin >> v;

    vector<pair<int,int>> s(26, {0,0});
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int l = v[i];
        int upper = 1;
        if (v[i] >= 'a' && v[i] <= 'z') {
            l -= 'a' - 'A';
            upper = -1;
        }
        l -= 'A';
       
        if (upper == -1) {
            if (s[l].second > 0) {
                s[l].second--;
                ans++;
            }
            else if (b > 0 && s[l].first > 0) {
                s[l].first--;
                ans++;
                b--;
            } else {
                s[l].first++;
            }
        } else {
            if (s[l].first > 0) {
                s[l].first--;
                ans++;
            } else if (b > 0 && s[l].second > 0) {
                s[l].second--;
                ans++;
                b--;
            } else {
                s[l].first++;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    int n; cin >> n;
    while (n--) solve();
}