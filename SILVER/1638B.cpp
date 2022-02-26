#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) cin >> v[i];

    int evenmin = -1;
    int oddmin = -1;

    vector<int> check(2, -1);
    for (int i = 0 ; i < n ; i++) {
        if (check[v[i]%2] > v[i]) {
            cout << "NO" << endl;
            return;
        } else {
            check[v[i]%2] = v[i];
        }
    }
    cout << "YES" << endl;
}

int main() {
    
    int n;
    cin >> n;
    while (n--) solve();

}
