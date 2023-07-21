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
    vector<int> v(n);
    bit.resize(n+1, 0);

    for (int i = 0 ; i < n ; i++) cin >> v[i];

    int m = 1;
    add(bit, v[n-1], 1);
    for (int i = n-2 ; i >= 0 ; i--) {
        if (v[i] < v[i+1]) {
            m++;
            add(bit, v[i], 1);
        }
        else {
            break;
        }
    }

    cout << n-m << endl;
    for (int i = 0 ; i < n-m ; i++) {
        int cur = n-m-i-1;

        //cout << v[i] << " " << query(bit, v[i]) << endl;
        cout << query(bit, v[i]) + cur << " ";
        add(bit, v[i], 1);
    }
    cout << endl;
}