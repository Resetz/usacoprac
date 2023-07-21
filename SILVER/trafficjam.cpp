#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<long long, long long> a, const pair<long long, long long> b) {
    if (a.first == b.first || a.first > b.first) return false;
    return a.first < b.second;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<long long, long long>> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].second = v[i].first + v[i].second*k;
    }

    sort(v.rbegin(), v.rend());

    int groups = 1;
    pair<long long, long long> cur = v[0];
    for (int i = 1 ; i < n ; i++) {
        //cout << "{" << v[i].first << ", " << v[i].second << "} -> {" << cur.first << ", "  << cur.second << "}" << endl;
        if (v[i].second >= cur.second) {
            continue;
        } else {
            groups++;
            cur = v[i];
        }
    }
    cout << groups << endl;
}

