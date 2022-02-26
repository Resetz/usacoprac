#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    unsigned long long n, m, k, q;
    cin >> n >> m >> k >> q;
 
    vector<pair<unsigned long long, unsigned long long>> qs(q);
    for (int i = 0 ; i < q ; i++) {
        cin >> qs[i].first >> qs[i].second;
        qs[i].first--;
        qs[i].second--;
    }
 
    vector<bool> rows(n, false);
    vector<bool> cols(m, false);
    int rc = 0;
    int cc = 0;
 
    unsigned long long ans = 1;
    for (int i = q-1 ; i >= 0 ; i--) {
        if (rc == n || cc == m) {
            break;
        }

        bool good = ((rows[qs[i].first] == false) || (cols[qs[i].second] == false));
        if (good) {
            ans *= k;
            ans = ans % 998244353;
        }   
        if (!rows[qs[i].first]) rc++;
        if (!cols[qs[i].second]) cc++;
        rows[qs[i].first] = true;
        cols[qs[i].second] = true;
    }
    cout << ans << endl;
}
 
int main() {
    int n;
    cin >> n;
    while (n--) solve();
}