#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long cur = 0;
    long long prevd = -1;
    map<long long, long long> m;
    set<long long> s;
    s.insert(0);
    for (int i = 0 ; i < n ; i++) {
        long long l;
        char c;
        cin >> l >> c;
        long long d = c == 'R';

        l = l * (d ? 1 : -1) + cur;
        s.insert(l);

        if (prevd == -1) {
            if (d) {
                m[0] = 1;
                m[l] = -1;
            } else {
                m[0] = -1;
                m[l] = 1;
            }
        } else if (prevd == d) { // same direction
            if (d) {
                m[cur]++;
                //cout << cur << " + " << endl;
                //cout << l << " - " << endl;
                if (m.find(l) != m.end()) {
                    m[l]--;
                } else {
                    m[l] = -1;
                }
            } else {
                m[cur]--;
                //cout << cur << " - " << endl;
                //cout << l << " + " << endl;
                if (m.find(l) != m.end()) {
                    m[l]++;
                } else {
                    m[l] = 1;
                }
            }
        } 
        else {
            if (d) { //right
                //cout << cur << " + " << endl;
                //cout << l << " - " << endl;
                m[cur]++;
                if (m.find(l) != m.end()) {
                    m[l]--;
                } else {
                    m[l] = -1;
                }
            } else {
                //cout << cur << " - " << endl;
                //cout << l << " + " << endl;
                m[cur]--;
                if (m.find(l) != m.end()) {
                    m[l]++;
                } else {
                    m[l] = 1;
                }
            }
        }

        prevd = d;
        cur = l;
    }

    vector<pair<long long, long long>> v;
    for (long long l : s) {
        //cout << "m[" << l << "] = " << m[l] << endl;
        v.push_back(pair<long long, long long>{l, m[l]});
    }

    sort(v.begin(), v.end());
    long long prev = v[0].first;
    cur = v[0].second;

    long long ans = 0;
    for (int i = 1 ; i < v.size() ; i++) {
       // cout << prev << " " << cur << endl;
        if (cur >= k) {
            ans += v[i].first - prev;
        }
        cur += v[i].second;
        prev = v[i].first;
    }
    cout << ans << endl;
}