#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    int a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    float ans = a;
    for (int i = 1 ; i < n ; i++) {
        ans += min((float)(v[i]-v[i-1])*b/2, (float)a);
    }
    if ((float) (ans - (int) ans) == 0.5) {
        cout << fixed << setprecision(1) << ans ;
    } else {
        cout << fixed << setprecision(0) << ans << endl;
    }
}