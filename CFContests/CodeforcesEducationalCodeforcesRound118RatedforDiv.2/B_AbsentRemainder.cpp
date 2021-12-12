// time-limit: 2000
// problem-url: https://codeforces.com/contest/1613/problem/B

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    int m = v[0];
    for (int i = 0 ; i < n ; i++) {
        m = min(v[i], m);
    }

    int printed = 0;
    for (int i = 0 ; i < n ; i++) {
        if (printed >= n/2) {
            break;
        }
        if (v[i] != m) {
            cout << v[i] << " " << m << endl;
            printed++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}