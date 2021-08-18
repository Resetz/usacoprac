#include <iostream>

using namespace std;

void solve() {
    unsigned long long n;
    cin >> n;
    n = max(6ULL, n);
    if (n % 2 == 1) n++;
    cout << n * 5 / 2 << endl;
    
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}