#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    vector<pair<long long,long long>> pf;

    long long k, m, n;
    cin >> k >> m >> n;
    pf.push_back(pair<long long,long long>(-1, 0));
    for (long long i = 0 ; i < k ; i++) {
        long long p, v;
        cin >> p >> v;
        pf.push_back({p ,v});
    }
    sort(pf.begin(), pf.end(), [](pair<long long, long long> a, pair<long long,long long> b) -> long long { return a.first < b.first; });

    vector<long long> cows;
    for (long long i = 0 ; i < m ; i++) {
        long long p;
        cin >> p;
        cows.push_back(p);
    }
    cows.push_back(LLONG_MAX);
    sort(cows.begin(), cows.end());

    for (long long i = 1; i <= k ; i++) {
        pf[i].second += pf[i-1].second;
    }

    long long left = 0;
    long long cur = 1;
    vector<long long> tot;
    for (long long i = 0 ; i < cows.size() ; i++) {
        vector<long long> valid;

        long long last = cur;

        while (cur <= k && pf[cur].first <= cows[i]) {
            valid.push_back(cur);
            cur++;
        }
        if (valid.size() > 0 && cows[i] == pf[cur-1].first) {
            cur--;
            valid.pop_back();
        } else if (valid.size() == 0) { 
            left = cows[i];
            continue;
        }

        long long cost = 0;
        for (long long j = 0; j < valid.size(); j++) {
            long long other = max(left, cows[i] - (cows[i] - pf[valid[j]].first) * 2);
            long long mid = (other + left)/2;
            long long ind = (upper_bound(pf.begin(), pf.end(), pair<long long,long long>(mid, LLONG_MAX))-1)->second;
            cost = max(pf[valid[j]].second - ind, cost);
        }
        for (long long j = 0; j < valid.size(); j++) {
            long long right = min(cows[i], left + (pf[valid[j]].first - left) * 2);
            long long mid = (right + left)/2;
            long long ind = (lower_bound(pf.begin(), pf.end(), pair<long long,long long>(mid, LLONG_MAX))-1)->second;
            cost = max(ind - pf[valid[j]-1].second, cost);
        }
        tot.push_back(cost);
        left = cows[i];
    } 
    sort(tot.begin(), tot.end());
    unsigned long long ans = 0;
    for (long long i = 0; i < n ; i++) {
        ans += tot[tot.size() - 1 - i];
    }
    cout << ans << endl;
 }