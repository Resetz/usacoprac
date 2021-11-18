// time-limit: 200
// problem-url: https://codeforces.com/contest/1598/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    long long sum = 0;
    map<int,int> m;
    for (int i = 0 ; i < n ; i++ ) {
        cin >> v[i];
        sum += v[i];
        m[v[i]]++;
    }
    sort(v.begin(), v.end());
    unsigned long long a = (sum * 2) % n;
    cerr << a << endl;
    unsigned long long ans = 0;
    if (a == 0) {
        // find all
        a = (sum * 2) / n;
        for (int i = 0 ; i < n ; i++) {
            int lf = a - v[i];
            if (m[lf] == 0) {
                continue;
            } else {
                if (lf == v[i]) {
                    ans += m[lf] - 1;
                } else {
                    ans += m[lf];
                }
            }
        }
    } 
    cout << ans/2 << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}