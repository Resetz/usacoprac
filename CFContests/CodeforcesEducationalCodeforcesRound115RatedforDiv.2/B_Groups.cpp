// time-limit: 4000
// problem-url: https://codeforces.com/contest/1598/problem/B
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0 ; i < n ; i++) {
        vector<int> a(5);
        cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
        v[i] = a;
    }

    for (int i = 0 ; i < 4 ; i++) {
        for (int j = i+1; j < 5; j++) {
            int neither, a, b, both;
            neither = a = b = both = 0;
            for (int k = 0 ; k < n ; k++) {
                if (v[k][i] && v[k][j]) both++;
                if (!v[k][i] && v[k][j]) b++;
                if (v[k][i] && !v[k][j]) a++;
                if (!v[k][i] && !v[k][j]) neither++;
            }
            if (neither > 0) {
                continue;
            } else if (a <= n/2 && b <= n/2) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    int n;
    cin >> n; while (n--) solve();
}