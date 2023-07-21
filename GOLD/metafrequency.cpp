#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> k >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    v.push_back(INT_MAX);

    int q;
    cin >> q;
    vector<pair<int,int>> m(q);
    for (int i = 0; i < q; i++) {
        cin >> m[i].first;
        m[i].second = i;
    }

    sort(m.begin(), m.end());
    vector<int> ans(q, 0);
    int lst = 0;
    int lstp = 0;
    int cq = 0; //query number
    int p = 0;
    set<int> s;
    while (p < n+1) {
        int c = v[p++];
        while (p < n+1 && v[p] == c) {
            p++;
        }
        //cout << p << " " << cq << endl;
        while (cq < q && m[cq].first < p) {
            //cout << cq << " " << m[cq].first << " " << m[cq].second << " " << lstp << " " << p << " " << c << endl;
            ans[m[cq].second] = (c== INT_MAX ? k : c-1);
            cq++;
        }
        lstp = c;
    }
    for (int i = 0 ; i < q ; i++) {
        cout << ans[i] << endl;
    }

}