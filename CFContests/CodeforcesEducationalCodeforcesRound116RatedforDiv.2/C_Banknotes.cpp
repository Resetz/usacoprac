// time-limit: 2000
// problem-url: https://codeforces.com/contest/1606/problem/C

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

unsigned long long dp[10] = {1};

void solve() {
    long long a, b;
    cin >> a >> b;
    vector<int> v(a);

    for (int i = 0 ; i < a; i++) {
        cin >> v[i];
    }

    unsigned long long total = 0;
    unsigned long long sub = 0;
    for (int i = 0 ; i < a-1; i++) {
        unsigned long long mult = dp[v[i+1] - v[i]] - 1;
        if (sub + mult > b) {
            total += (b - sub+1) * dp[v[i]];
            cout << total << endl;
            return;
        }
        total += mult * dp[v[i]];
        sub += mult;
    }
    total += (b - sub + 1) * dp[v[a-1]];
    cout << total << endl;
}

int main() {

    unsigned long long start = 1;
    for (int i = 0 ; i < 10; i++) {
        dp[i] = start;
        cerr << dp[i] << " " << endl;
        start *= 10;
    }

    int n;
    cin >> n;
    while (n--) solve();
}