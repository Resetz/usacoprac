#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int n, m; cin >> n >> m;
    bool good = true;
    for (int i = 0 ; i < m ; i++) {
        int a,b;
        cin >> a >> b;
        good = good && ((b-a+1) % 2 == 0);
    }
    if (good) {
        cout << "Y" << endl;
        for (int i = 0 ; i < n ; i++) {
            cout << (i%2 ? "M" : "T");
        }
        cout << endl;
    } else {
        cout << "N" << endl;
    }
}
int main() {
    int n;
    cin >> n;
    while (n--) solve();
}