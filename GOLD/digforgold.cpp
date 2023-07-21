#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void add(vector<long long> &b, long long at, long long val) {
    while ( at < b.size() ) {
        b[at] += val;
        //cout << at << " +" << val << endl;
        at += at & (-at);
    }
}

long long query(vector<long long> &b, long long f) {
    long long total = 0;
    while (f > 0) {

        total += b[f];

        f -= f & (-f);
    }
    return total;
}


int main() {
    long long n,m,k;
    cin >> n >> m >> k;
    vector<pair<long long,long long>> v(m);
    vector<long long> a;
    for (long long i = 0 ; i < m ; i++) {
        cin >> v[i].first >> v[i].second;
        a.push_back(v[i].first);
        a.push_back(v[i].first+k);
    }

    sort(v.begin(), v.end());
    vector<long long> s(m);
    vector<long long> d = a;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (long long i = 0; i < m; ++i) {
        v[i].first = lower_bound(d.begin(), d.end(), v[i].first) - d.begin()+1;
        s[i] = lower_bound(d.begin(), d.end(), v[i].first+k) - d.begin()+1;
    }
    cout << "here" << endl;
    vector<long long> bit(m*2+100);
    long long l = 0;
    long long r = 0;
    long long c = 0;
    long long on;
    long long ans = 0;
    while (r < m) {
       // on = l;
        while (c < m && r < m && v[c].second <= v[l].second) {
            cout << "a" << " " << l << " " << r << endl;  
            add(bit, v[c].first, 1);
            c++;
            r++;
        }
       // cout << l << " " << r << endl;
        while (l < n && v[l].first == v[on].first) {
            cout << "b" << " " << l << " " << r << endl;  
            ans = max(ans, query(bit, s[on]) - query(bit, v[on].first-1));
            add(bit, v[on].first, -1);
            l++;
        }
    }
    cout << ans << endl;
}