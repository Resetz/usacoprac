#include <iostream>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
        if (b == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else if (a == 3 || a == 2) {
        if (b < 4) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}