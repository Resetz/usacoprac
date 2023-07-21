#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>

using namespace std;
using namespace std::__detail;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0 ; i < n ; i++) cin >> a[i];
    for (int i = 0 ; i < n ; i++) cin >> b[i];

    int parity = -1;
    bool ans = true;
    for (int i = 0 ; i < n ; i++) {
        if (a[i] == 0 && b[i] == 0) continue;
        int g = __gcd(a[i], b[i]);
        if (parity == -1) {
            parity = max(a[i]/g,b[i]/g)%2; 
        } else if (max(a[i]/g, b[i]/g)%2 != parity) {
            ans = false;
            break;
        }
    }
    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}