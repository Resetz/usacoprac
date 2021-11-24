#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int ans = -1;
    for (int i = 0 ; i < n-1 ; i++) {
        if (v[i] - v[i+1]) {
            if (ans == -1) {
                ans = v[i] - v[i+1];
            } else {
                ans = __gcd(ans, v[i] - v[i+1]);
            }
        }
    }
    cout << ans << endl;
}

int main () {
    int n;
    cin >> n;
    while (n--) solve();
}