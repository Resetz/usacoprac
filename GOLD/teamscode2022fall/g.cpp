#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int a,b,c;
    cin >> a >> b >> c;

    int last = 0;
    for (int i = 0 ; i < 32 ; i++) {
        if (c & (1 << i)) last = i;
    }
    int num = 0;
    for (int i = 0 ; i < last ; i++) {
        num += (1 << i);
    }

    if ((a & num) != num) {
        a = a & num;
    } 
    if ((b & num) != num) {
        b -= (1 << (last+1));
        b |= num;
    }
    //cout << last << " " << num << " " << a << " " << b << endl;
    if (b < a) cout << 0;
    else {
        cout << (b >> last) - (a >> last) + 1 << endl;
    }
}

int main() {
    int n; cin >> n;while (n--) solve();
}