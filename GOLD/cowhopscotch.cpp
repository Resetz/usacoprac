#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class segtree {
    long long n;
    vector<long long> arr;
    segtree(long long n, vector<long long> &a) {
        arr = vector<long long>(n*2);
        for (long long i = 0 ; i < n ; i++) {
            arr[n+i] = a[i];
        }
        for (long long i = n-1 ; i > 0 ; i--) {
            arr[i] = max(arr[i << 1], arr[i << 1 + 1]);
        }
    }

    void update(long long at, long long amt) {
        at += n;
        arr[at] = amt;
        for (long long i = at ; i > 1 ; i = i >> 1) {
            arr[i>>1] = max(arr[i], arr[i^1]);
        } 
    }

    long long query(long long f, long long t) {
        long long ret = 0;
        f+=n; t+=n;
        while (t > f) {
            if (f % 2 == 1) {
                ret = max(ret, arr[f++]);
            }
            if (t % 2 == 1) {
                ret = max(ret, arr[--t]);
            }
            f = f >> 1;
            t = t >> 1;
        }
        return ret;
    }
};

typedef struct {
    long long cur;
    long long value;
    long long next;
} ins;

int comp(ins a, ins b) {
    if (a.value == b.value) {
        return a.next < b.next;
    } 
    return a.value < b.value;
}

int main() {

    long long n, k;
    cin >> n >> k;

    vector<long long> v(n+1, 0);
    for (long long i = 0 ; i < n ; i++) {
        cin >> v[i+1];
    }

    //long long m = -LLONG_MAX;
    vector<pair<long long,long long>> dp(n+1, pair<long long, long long>{LLONG_MIN, LLONG_MIN});
    //cout << dp[0].first << " " << dp[0].second << endl;
    //cout << dp[0].first << " " << dp[0].second << endl;
    //cout << dp[0].first << " " << dp[0].second << endl;
    //cout << dp[0].first << " " << dp[0].second << endl;
    //cout << dp[0].first << " " << dp[0].second << endl;
    //set<pair<long long,long long>, decltype(comp)*> cur(comp); // seg tree?
    //set<pair<long long,long long>> s; // seg tree?
    set<ins, decltype(comp)*> s(comp);
    s.insert(ins{0, 0, 0});
    for (long long i = 1 ; i <= n ; i++) {
        ins it = *(s.rbegin());
        cout << it.cur << " " << it.value << " " << it.next << " v[" << i << "] = " << v[i] << endl;
        long long to = it.next;
        it.cur = it.next;
        it.value += v[i];
        it.next = i;
        if (comp({0, dp[it.cur].first, dp[it.cur].second}, it)) {
            auto r = s.find({it.cur, dp[it.cur].first, dp[it.cur].second});
            if (r != s.end()) {
                s.erase(r);
            } 
            dp[it.cur] = {it.value, it.next};
            cout << "inserting " << it.cur << " " << it.value << " " << it.next << endl;
            s.insert(it);
        } 
        if (i >= k) {
            //cout << "erase " << i-k << " " << dp[i-k].first << " " << dp[i-k].second << " " << (s.find(ins{i-k, dp[i-k].first, dp[i-k].second}) == s.end()) << endl;
            
            auto r = s.find(ins{i-k, dp[i-k].first, dp[i-k].second});
            if (r != s.end()) s.erase(s.find(ins{i-k, dp[i-k].first, dp[i-k].second}));
            //cout << "erase success" << endl;
        }
        s.insert({i, dp[i].first, dp[i].second});
    }
    long long ans = 0;
    for (long long i = 0 ; i <= n ; i++) {
        ans = max(ans, dp[i].first);
    }
    cout << ans << endl;
    
}