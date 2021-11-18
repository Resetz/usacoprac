#include <iostream>
#include <iomanip>
#include <vector>
#include <set>

using namespace std;


void solve() {
    unsigned long long n;
    cin >> n;
    vector<unsigned long long> a(n);
    vector<unsigned long long> b(n);
    vector<pair<unsigned long long,unsigned long long>> p(n);

    for (int i = 0 ; i < n ; i++) {
        unsigned long long f, s;
        cin >> f >> s;
        f--;
        s--;
        a[f]++;
        b[s]++;
        p[i] = {f,s};
    }
    unsigned long long ans = (n * (n-1) * (n-2))/6; //n choose 3
    for (int i = 0; i < n; i++) {
        unsigned long long c = a[p[i].first]-1;
        unsigned long long d = b[p[i].second]-1;
        ans -= c * d;
    }
    cout << ans << endl;

}

int main() {

    int n;
    cin >> n;

    while (n--) solve();

}