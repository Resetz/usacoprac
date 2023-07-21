#include <iostream>
#include <vector>
#include <string>

using namespace std;


void solve() {
    #define int long long
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    //ax + by = c
    //by + ax = d
    int det = a*a - b*b;
    int deta = c*a - b*d;
    int detb = d*a - b*c;

    cout << det << " " << deta << " " << detb << endl;
    if ((deta/det)*det == deta && (detb/det)*det == detb) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
int32_t main() {
    int n;
    cin >> n;
    while (n--) solve();
}
