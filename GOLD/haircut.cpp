#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bit;

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
    vector<int> v(n);
    bit.resize(n+1);
    vector<pair<int,int>> order;
    vector<long long> go(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];

        go[v[i]] += i - query(bit, v[i]+1);
        add(bit, v[i]+1, 1);

        //order.push_back({v[i], i+1});
        //add(bit, i+1, 1);
    }
    cout << 0 << endl;

    long long ans = 0;
    for (int i = 0 ; i < n-1 ; i++) {
        
        ans += go[i];
        cout << ans << endl;
    }
    
}