#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

long long MOD = 100000007;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> pf(n+1, 1);
    long long p = 1;
    vector<long long> pfp(n+1, 1);
    for (int i = 0 ; i < n ; i++) {
        pf[i+1] = (pf[i] + p * (s[i]-'a'+1)) % MOD;
        cout << pf[i+1] << endl;
        p = (p * 31) % MOD;
        pfp[i] = p;
    }
    set<long long> ans;
    for (int i = 0 ; i < n-2 ; i++) {
        cout << (((pf[i] * pf[n] / pf[i+2] % MOD))) << " " << ans.size() << endl;
        ans.insert(pf[i] + ((pf[n]-pf[i+1]) * p));
    }
    cout << ans.size() << endl;
}

int main() {
    int n;
    cin >> n; while (n--) solve();
}