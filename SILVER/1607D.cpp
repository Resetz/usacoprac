#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fineilldoitmyselfmin(vector<int> v) {
    int ret = v[0];
    for (int i = 0 ; i < v.size() ; i++) {
        ret = min(v[i], ret);
    }
    return ret;
}

void damnit() {
    int n;
    cin >> n;
    vector<int> v;
    string s;
    v.resize(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }
    cin >> s;

    vector<int> r;
    vector<int> b;
    for (int i = 0 ; i < n ; i++) {
        if (s[i] == 'R') r.push_back(v[i]);
        else r.push_back(v[i]);
    }
    sort(r.begin(), r.end());
    sort(b.begin(), b.end());

    cout << "here" << endl;
    int minr = (fineilldoitmyselfmin(r));
    int minb = (fineilldoitmyselfmin(b));
    
    int ca = 0;
    int cb = 0;
    cout << "here2" << endl;
    for (int i = 1 ; i <= n ; i++) {
        if (r[ca] - minr == i) {
            ca++;
        } else if  (b[cb] - minb == i) {
            cb++;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v;
    string s;
    v.resize(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }
    cin >> s;

    vector<int> r;
    vector<int> b;
    for (int i = 0 ; i < n ; i++) {
        if (s[i] == 'R') r.push_back(v[i]);
        else b.push_back(v[i]);
    }
    sort(r.begin(), r.end());
    sort(b.begin(), b.end());
    int last = 1;
    for (int i = 0 ; i < b.size() ; i++) {
        if (b[i] >= last) {
            last++;
            continue;
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = 0 ; i < r.size() ; i++) {
        if (r[i] <= last) {
            last++;
            continue;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

    
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}