#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    unsigned long long k,m,n;
    cin >> k >> m >> n;

    vector<pair<unsigned long long, unsigned long long>> patches(k+m);

    for (int i = 0; i < k; i++) {
        cin >> patches[i].first >> patches[i].second;
    }
    for (int i = 0 ; i < m; i++) {
        cin >> patches[i+k].first;
        patches[i+k].second = -1;
    }

    sort(patches.begin(), patches.end());

    vector<unsigned long long> pfs(k+m+1, 0);

    for (int i = 1 ; i <= k+m ; i++) {
        pfs[i] = pfs[i-1] + max(0ull, patches[i-1].second);
    }

    vector<unsigned long long> intervals;

    int f, t;
    int total = 0;
    f = -1;
    for (int i = 0 ; i < k+m ; i++) {
        if (patches[i].second == -1) {
            // end
            if (f == -1) {
                intervals.push_back(total);
                //cout << "1: " << total << endl;
            } else { 
                unsigned long long m = (patches[f].first + patches[i].first) / 2;
                //cout << f << " -> " << i  << " | " << m << endl;
                
                //find best 
                int cur = 0;
                int best = 0;
                int r = f;
                for (int l = f+1 ; l < i ; l++) {
                    while (r + 1 < i && (patches[r+1].first - patches[l].first) * 2 + patches[f].first < patches[i].first) {
                        r++;
                        cur += patches[r].second;
                    }
                    best = max(cur, best);
                    cur -= patches[l].second;
                }
                intervals.push_back(best);
                intervals.push_back(total - best);
            }
            f = i;
            total = 0;
        } else {
            total += patches[i].second;
        }
    }
    intervals.push_back(total);
    sort(rbegin(intervals), rend(intervals));
    unsigned long long ans = 0;
    for (int i = 0 ; i < min(n, (unsigned long long) intervals.size()) ; i++) {
        ans += intervals[i];
    }
    cout << ans << endl;
}