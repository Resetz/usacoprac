#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>

using namespace std;

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
        int g = gcd(a[i], b[i]);
        if (i == 0) {
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