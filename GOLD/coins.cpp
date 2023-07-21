#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long a,b;
    cin >> a >> b;
    if (a % 2 == 0) {
        cout << "YES" << endl;
    } else if ((a-b) % 2 == 0) {
        cout << "YES" << endl;
    } else if ((a-b-b) > 0 && (a-b-b) % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}