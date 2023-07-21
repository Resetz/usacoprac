#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    bool even = true;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    even &= !(v[0] % 2);
    if (v[0] % 2 == 1) {
        cout << "YES" << endl;
    } else {
        for (int i = 0 ; i < n ; i++) {
            even &= !(v[i] % 2);
        }
        if (even) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

}
int main() {
    int n;
    cin >> n;
    while(n--) solve();
}