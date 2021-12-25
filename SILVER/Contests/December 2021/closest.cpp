#include <iostream>
#include <vector>
#include <algorithm>

#define ull long long

using namespace std;


int main() {
    ull k,m,n;
    cin >> k >> m >> n;

    vector<pair<ull,ull>> p;

    for (ull i = 0; i < k ; i ++) {
        ull a, b;
        cin >> a >> b;
        p.push_back(pair<ull,ull>(a,b));
    }

    ull g;

    vector<ull> pos;
    for (ull i = 0; i < m ; i++) {
        ull num;
        cin >> num;
        pos.push_back(num);
    }
    pos.push_back((ull)10e9);

    sort(pos.begin(), pos.end());
    sort(p.begin(), p.end(), [](pair<ull,ull> a, pair<ull,ull> b) -> ull {
        return a.first < b.first;
    });

    ull left = 0;
    ull go = 0;

    vector<unsigned long long> cost;
    for (ull i = 0 ; i < pos.size() ; i++) {
        vector<pair<ull,ull>> valid;
        cout << "from " << left << " " << pos[i] << " " << go << ": ";
        while (go < p.size() && p[go].first <= pos[i]) {
            cout << p[go].first << " ";
            valid.push_back(p[go]);
            go++;
        }
        cout << endl;
        if (valid.size() > 0 && pos[i] == p[go-1].first) {
            go--;
        } else if (valid.size() == 0) {
            left = pos[i];
            continue;
        }
        ull next = min(pos[i], left + (valid[0].first - left) * 2);
        cout << "-> " << next;
        ull ind = 0;
        unsigned long long s = 0;
        while (ind < valid.size()) {
            if (valid[ind].first < next || (valid[ind].first - next + 1 < pos[i] - valid[ind].first)) {
                s += valid[ind].second;
            } else {
                break;
            }
            ind++;
        }
        if (next == left) {
            s = 0;
        }
        cout << " " << s << endl;

        ull l = max(left, pos[i] - (pos[i] - valid[valid.size()-1].first) * 2);
        cout << "-> " << l;
        ind = valid.size()-1;
        unsigned long long s2 = 0;
        while (ind >= 0) {
            if (valid[ind].first > l || (l - valid[ind].first + 1 < valid[ind].first - next)) {
                s2 += valid[ind].second;
            } else {
                break;
            }
            ind--;
        } 
        if (l == pos[i]) {
            s2 = 0;
        }

        cout << " " << s2 << endl;

        cost.push_back(max(s,s2));
        left = pos[i];
    }
    sort(cost.begin(), cost.end());
    unsigned long long ans = 0;
    for (int i = 0; i < n ; i++) {
        ans += cost[cost.size()-1 - i];
    }
    for (int i = 0 ; i < cost.size() ; i++) {
        cout << cost[i] << endl;
    }
    cout << ans << endl;
}