#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lbit;
vector<int> rbit;

void add(vector<int> &b, int at, int val) {
    while ( at < b.size() ) {
        b[at] += val;
        //cout << at << " +" << val << endl;
        at += at & (-at);
    }
}

int query(vector<int> &b, int f) {
    int total = 0;
    while (f > 0) {

        total += b[f];

        f -= f & (-f);
    }
    return total;
}

int range(vector<int> &b, int f, int t) {
    //cout << query(b,f) << " " << query(b,t) << endl;
    return query(b, f) - query(b, t);
}

int main() {
    int n;
    cin >> n;
    lbit.resize(n+2);
    rbit.resize(n+2);

    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
        add(rbit, i+1, 1);
    }

    vector<int> d = v;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (int i = 0; i < n; ++i) {
        v[i] = lower_bound(d.begin(), d.end(), v[i]) - d.begin();
    }


    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
       // cout << "- " << i <<  " " << v[i]+1 << endl;
        int a = range(lbit, n+1, v[i]+1);
        int b = range(rbit, n+1, v[i]+1);

        //cout << " = " << a << " " << b << endl;
        if (max(a,b) > 2*min(a,b)) {
            //cout << i << endl;
            ans++;
        }

        add(lbit, v[i]+1, 1);
        add(rbit, v[i]+1, -1);
    }
    cout << ans << endl;
}
