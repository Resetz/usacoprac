#include <iostream>
#include <map>
#include <random>
#include <algorithm>
#include <set>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef DLOCAL

    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);

    #endif

    mt19937_64 gen;
    vector<long> hash(1000001);

    //manually hash each subset
    for (int i = 0 ; i < 1000001 ; i++) {
        hash[i] = gen();
    }
    //cout << 10e6 << endl;

    long long n;
    cin >> n;
    map<long, int> m;
    long ans = (n) * (n-1) / 2;
    for (int i = 0 ; i < n ; i++) {
        vector<int> fl(5);
        for (int j = 0 ; j < 5 ; j++) cin >> fl[j];
        sort(fl.begin(), fl.end());
        //cout << "here" << endl;
        for (int j = 1 ; j < 32 ; j++) {
            long cur = 0;
            int size = 0;
            for (int k = 0 ; k < 5; k ++) {
                if ((j >> k) & 1) {
                    //cout << fl[k] << endl;
                    cur ^= hash[fl[k]];
                    size++;
                }
            }

            if (size % 2) {
                ans -= m[cur];
            } else {
                ans += m[cur];
            }
            m[cur]++;
            //if (++m[cur] == 2) {
            //    s.insert({size, cur});
            //}
        }
    }
    cout << ans << endl;

}