#include <iostream>
#include <vector>
#include <algorithm>
#define mod ((int)(1e9+7))
using namespace std;

int main() {
#define int unsigned long long 
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }
    vector<int> power2(n, 1);
    for (int i = 1 ; i < n ; i++) {
        power2[i] = power2[i-1]*2 % mod;
    }

    vector<int> p(2*n+1, 0);
    for (int i = 0 ; i < n ; i++) {
        p[v[i].first]++;
        p[v[i].second]--;
    }

    for (int i = 1 ; i <= 2*n ; i++) {
        p[i] += p[i-1];
    }
    int total = 0;
    for (int i = 0 ; i < n ; i++) {
        total = (total + power2[n-1-p[v[i].first-1]])%mod;
    }
    cout << total << endl;
/*    sort(v.begin(), v.end(), [](pair<int,int> p, pair<int,int> q) -> int {
        return p.second < q.second;
    });
    //vector<vector<int>> total;


    vector<int> dp(2*n, 0);
    int last = 0;
    int going = 1;
    for (int i = 0 ; i < n ; i++) {
        if (v[i].first < last)  {
            going++;
        } else {
            going = 1;
        }
        dp[v[i].second] = going;
        last = v[i].second;
        
    }
    vector<int> pfdp(2*n+1, 0);
    for (int i = 0 ; i < 2*n ; i++) {
        pfdp[i+1] = pfdp[i]+dp[i];
    }
    

    vector<int> cur(2*n, 0);
    vector<int> pfcur(2*n+1, 0);


    int pre = v[0].second;
    int mult = 1;
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int k = 0;
        for (int j = 0 ; j < 2*n ; j++) {
            //each point
            if (j == v[k].second) {
                int l,r;
                l = v[k].first;
                r = v[k].second;
                cur[r] = (pfdp[l] + (pfcur[r] - pfcur[l])) % mod;
                k++;
            }
            pfcur[j+1] = pfcur[j] + cur[j];
        }
        for (int j = 0 ; j < n*2 ; j++) {
            ans += (mult * dp[j]) % mod;
            ans %= mod;
            //cout << dp[j] << " ";
        }
        //cout << endl;
        dp = cur;
        pfdp = pfcur;
        for (int j = 0; j < n*2 ; j++) {
            cur[j] = 0;
            pfcur[j] = 0;
        }
        mult++;
    }
    for (int j = 0 ; j < n*2 ; j++) {
            ans += (mult * dp[j]) % mod;
            ans %= mod;
        }
    cout << ans << endl;*/
}