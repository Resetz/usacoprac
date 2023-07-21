#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

//first cow will never pass

using namespace std;

void add(vector<long long> &b, int at, int val) {
    while ( at < b.size() ) {
        b[at] += val;
        //cout << at << " +" << val << endl;
        at += at & (-at);
    }
}

long long query(vector<long long> &b, int f) {
    long long total = 0;
    while (f > 0) {

        total += b[f];

        f -= f & (-f);
    }
    return total;
}


int main() {
    #define int long long
    int n, l, c;
    cin >> n >> l >> c;

    vector<int> v(n);
    int maxi = 0;
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
        maxi = max(v[i], maxi);
    }

    sort(v.begin(), v.end());
    int time = c*l;
    vector<long long> bit(n+2);
    c *= maxi;

    vector<int> b(n);


    for (int i = 0 ; i < n ; i++) {
        b[i] = ((v[i] * time) % c);
    }

    vector<int> d = b;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (int i = 0; i < n; ++i) {
        //bool iszero = false;
        //if (b[i] != 0) iszero = false;
        b[i] = lower_bound(d.begin(), d.end(), b[i]) - d.begin();
        //b[i] += (iszero ? 1ll : 0ll);
        b[i] = n - b[i];
    }
    //original value of a[i] can be obtained through d[a[i]]


    int cursum = 0;
    int ans = 0;
    int prev = INT_MAX;
    int prev_rem = 0;
    for (int i = 0 ; i < n ; i++) {
        int laps = (v[i] * time) / c;
        int remainder = b[i];
        //cout << v[i] << " " << cursum << " " << laps << " " << remainder << ": " << query(bit, remainder) << ", " << ans << endl;
        //cout << laps << " " << prev << endl;
        cursum += (laps-prev) * i;
        //cout << "+ " << cursum - query(bit, remainder-1) << endl;
        ans += cursum - query(bit, remainder-1);
        if (remainder != 0) {
            add(bit, remainder, 1);
        }
        prev = laps;
    }
    cout << ans << endl;
}