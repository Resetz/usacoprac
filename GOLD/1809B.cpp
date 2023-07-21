#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    unsigned long long n;
    cin >> n;
    n--;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    unsigned long long high = 10e9;
    unsigned long long  low = 0;
    unsigned long long  ans = 0;
    while (high >= low) {
        unsigned long long mid = low + (high-low)/2;
        //cout << mid << endl;
        if ((mid+1)*(mid+1)<=n) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    cout << ans+1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}