#include <iostream>
#include <vector>

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

    vector<int> v(n*2);
    bit.resize(n*2+1, 0);

    for (int i = 0 ; i < 2*n ; i++) {
        cin >> v[i];
    }

    vector<int> vis(n*2+1, -1);
    int ans = 0;
    for (int i = 0 ; i < 2*n ; i++) {
        if (vis[v[i]] == -1) {
            add(bit, i+1, 1);
            vis[v[i]] = i+1;
        } else {
            add(bit, vis[v[i]], -1);
            ans += range(bit, i+1, vis[v[i]]);
        }
    }
    cout << ans << endl;
}