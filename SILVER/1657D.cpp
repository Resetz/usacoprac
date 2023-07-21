#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x,y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
        cout << 0 << endl;
        return ;
    }

    long long s = sqrt(x*x+y*y);
    if (s*s == x*x+y*y) {
        cout << 1 << endl;
        return;
    }

    cout << 2 << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve(); 
}