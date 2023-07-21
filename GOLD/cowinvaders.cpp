#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    vector<bool> v[2];
    v[0].resize(a+1, false);
    v[1].resize(a+1, false);
    v[0][0] = true;
    for (int i = 0 ; i < 2 ; i++) {
        for (int j = 0 ; j <= a ; j++) {
            if (!v[i][j]) continue;
            if (j+b <= a) v[i][j+b] = true;
            if (j+c <= a) v[i][j+c] = true;
            if (i == 0) {
                v[i+1][j/2] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0 ; i < 2 ; i++) {
        for (int j = 0 ; j <= a ; j++) {
            if (v[i][j])
                ans = max(ans, j);
        }
    }
    cout << ans << endl;
}