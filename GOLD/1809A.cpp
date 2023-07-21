#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    string v;
    cin >> v;
    sort(v.begin(), v.end());
    int m = 0;
    int prev = v[0];
    int count = 1;
    for (int i = 1 ; i < 4 ; i++) {
        if (v[i] != prev) {
            m = max(m, count);
            prev = v[i];
            count = 1;
        } else {
            count++;
        }
    }
    m = max(m, count);
    if (m == 4) {
        cout << -1 << endl;
    } else if (m == 3) {
        cout << 6 << endl;
    } else if (m == 2) {
        cout << 4 << endl;
    } else {
        cout << 4 << endl;
    }
}


int main() {
    int n;
    cin >> n;

    while (n--) solve();
}