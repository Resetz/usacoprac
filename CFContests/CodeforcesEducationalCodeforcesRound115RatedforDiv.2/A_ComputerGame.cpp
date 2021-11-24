// time-limit: 2000
// problem-url: https://codeforces.com/contest/1598/problem/A
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<char> t(n), b(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> t[i];
    }
    for (int i = 0 ; i < n ; i++) {
        cin >> b[i];
    }

    for (int i = 0 ; i < n ; i++) {
        if (t[i] == '1' && b[i] == '1') {
            cout << "NO" << endl;
            return; 
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}