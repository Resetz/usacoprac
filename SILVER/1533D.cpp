#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


void solve() {
    string a,b;
    cin >> a >> b;
    int ptra = a.size()-1;
    int ptrb = b.size()-1;

    while (ptrb >= 0 && ptra >= 0) {
        if (a[ptra] == b[ptrb]) {
            ptra--;
            ptrb--;
        } else if (a[ptra] != b[ptrb]) {
            ptra -= 2;
        }
    }
    if (ptrb == -1) {
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