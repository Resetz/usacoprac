#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<unsigned long long> pf;
    pf.resize(n+1);
    

    map<unsigned long long, unsigned long long> dp;
    vector<unsigned long long> possible;

    dp[0]++;
    for (int i = 0 ; i < n ; i++) {
        char k;
        cin >> k;
        k -= '0';
        pf[i+1] = pf[i] + k;
        possible.push_back(pf[i+1]-i-1);
        dp[pf[i+1]-i-1]++;
        //cout << " - " << pf[i+1] - i-1 << endl;
    }
    sort(possible.begin(), possible.end());
    possible.resize(unique(possible.begin(), possible.end()) - possible.begin());
    unsigned long long ans = 0;
    for (int i = 0 ; i < possible.size() ; i++) {
        //cout << possible[i] << " ";
        //cout << dp[possible[i]] << endl;
        ans += (dp[possible[i]] * (dp[possible[i]]-1))/2;
    }
    cout << ans << endl;
}
int main() {
    int n;
    cin >> n;
    while (n--) solve();
}