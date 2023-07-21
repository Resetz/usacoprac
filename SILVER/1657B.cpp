#include <iostream>
#include <vector>

using namespace std;

void solve() {
    long long n, b, x, y;
    cin >> n >> b >> x >> y;

    int cur = 0;
    long long ans = 0;

    for (int i = 0 ; i < n ; i++) {
        if (cur + x > b) cur -= y;
        else {
            cur += x;
        }
        ans += cur;
    }
    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}