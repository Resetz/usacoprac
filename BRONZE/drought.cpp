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
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    unsigned long long ans = 0;

    for (int i = 1 ; i < n-1 ; i++) {
        if (v[i] > v[i-1]) {
            v[i+1] -= v[i] - v[i-1];
            ans += v[i] - v[i-1];
            v[i] = v[i-1];
        }
    }
    if (v[n-1] > v[n-2]) {
        cout << -1 << endl;
        return;
    }
    reverse(v.begin(), v.end());
    for (int i = 1 ; i < n-1 ; i++) {
        if (v[i] > v[i-1]) {
            v[i+1] -= v[i] - v[i-1];
            ans += v[i] - v[i-1];
            v[i] = v[i-1];
        }
    }
    if (v[n-1] > v[n-2] || v[0] < 0) {
        cout << -1 << endl;
        return;
    }

    cout << ans*2 << endl;
}

int main() {
    int n;
    cin >> n;
 
    while (n--) solve();
}