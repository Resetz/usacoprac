#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    string s;
    cin >> s;
    int a, b;
    a = b = 0;

    vector<pair<int,int>> as;
    vector<pair<int,int>> bs;

    for (int i = 0 ; i < n ; i++) {
        if (s[i] == '0') {
            b++;
            bs.push_back({v[i], i});
        } else {
            a++;
            as.push_back({v[i], i});
        }
    }

    sort(bs.begin(), bs.end());
    sort(as.begin(), as.end());

    sort(v.begin(), v.end());
    int l = 0;
    int r = n-1;

    int i = 0;

    vector<int> ans(n);
    while (i < bs.size()) { 
        ans[bs[i].second] = i+1;
        i++;
    }

    i = 0;
    while (i < as.size()) {
        ans[as[i].second] = i+b+1;
        i++;
    }
    for (int i = 0 ; i < n ; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}