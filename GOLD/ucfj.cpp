#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> bit;
vector<pair<int,int>> v;

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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++){
        cin >> v[i];
        v[i]--;
    }

    bit.resize(n+1, 0);
    vector<int> l(n, 0);
    long long ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (l[v[i-1]]) {
            add(bit, l[v[i-1]], -1);
        } 
        ans += query(bit, i) - query(bit, l[v[i-1]]);
        l[v[i-1]] = i;
        add(bit, i, 1);
    }
    cout << ans << endl;

    
}