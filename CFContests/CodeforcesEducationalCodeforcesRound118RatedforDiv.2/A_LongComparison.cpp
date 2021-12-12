// time-limit: 2000
// problem-url: https://codeforces.com/contest/1613/problem/A

#include <iostream>

using namespace std;

void solve() {
    long long n, p, n1, p1;
    cin >> n >> p >> n1 >> p1;

    long long sub = min(p,p1);
    p -= sub;
    p1 -= sub;
    if (p1 >= 7) {
        cout << "<" << endl;
    } else if (p >= 7) {
        cout << ">" << endl;
    } else {
        //log
        if (p == 0) {
            for (int i = 0; i < p1; i++) {
                n1 *= 10;
                if (n1 > n) {
                    cout << "<" << endl;
                    return;
                }
            }
            if (n1 > n) {
                cout << "<" << endl;
            } else if (n == n1) {
                cout << "=" << endl;
            } else {
                cout << ">" << endl;
            }
            return;
        } else {
            for (int i = 0 ; i < p ; i++) {
                n *= 10;
                if (n > n1) {
                    cout << ">" << endl;
                    return;
                }
            }
            if (n > n1) {
                cout << ">" << endl;
                return;
            } else if (n == n1) {
                cout << "=" << endl;
            } else {
                cout << "<" << endl;
            }
        }
    }
}


int main() {
    int n; cin >> n; while(n--) solve();
}