#include <iostream>

#include <vector>

using namespace std;

void solve() {
    int n, r;
    cin >> n >> r;

    int f = 0;
    if (r*2-1 > n) {
        cout << "-1" << endl;
    } else {
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (f < r && i == j && i % 2 == 0) {
                    cout << 'R';
                    f++;
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
    }
}
int main() {
    int n;
    cin >> n;
    while (n--) solve();
}