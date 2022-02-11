#include <iostream>

#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(2*n, vector<int>(2*n));

    for (int i = 0 ; i < 2*n ; i++) {
        for (int j = 0 ; j < 2*n ; j++) {
            cin >> v[i][j];
        }
    }

    unsigned long long ans = 0;
    for (int i = n; i < 2*n; i++) {
        for (int j = n ; j < 2*n ; j++) {
            ans += v[i][j];
        }
    }

    ans += min(min(min(v[0][2*n-1], v[n-1][2*n-1]),min(v[2*n-1][0], v[2*n-1][n-1])),
               min(min(v[0][n], v[n][0]), min(v[n-1][n], v[n][n-1])));

    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}