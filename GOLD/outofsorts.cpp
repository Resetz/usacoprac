#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bit;
vector<pair<int,int>> v;

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

int main() {
    int n;
    cin >> n;
    bit.resize(n+1);
    v.resize(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first;
        v[i].second = i+1;
    }

    sort(v.begin(), v.end());
    int ans = 1;
    for (int i = 0 ; i < n ; i++) {
        add(bit, v[i].second, 1);
        ans = max(ans, i+1 - query(bit, i+1));
    }
    cout << ans << endl;
}