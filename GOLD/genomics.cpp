#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

#define MOD (1000000007)
int n,m;
vector<vector<long long>> vs;
vector<vector<long long>> vb;

int go(int k) {
    for (int i = k ; i <= m ; i++) {
        set<long long> s;
        for (int j = 0 ; j < n ; j++) {
            //cout << j << " " << i << endl;
            //cout << vs[j][i+1] - vs[j][i-k] << endl;
            //cout << vs[j][i] << " " << vs[j][i-k] << endl;
            s.insert((vs[j][i] - vs[j][i-k] + MOD) % MOD);
        }
        
        //cout << "find" << endl;
        
        bool good = true;
        for (int j = 0 ; j < n ; j++) {
            //cout << j << " " << i << endl;
            //cout << vb[j][i+1] - vb[j][i-k] << endl;
            //cout << vb[j][i] << " " << vb[j][i-k] << endl;
            if (s.find((vb[j][i] - vb[j][i-k] + MOD) % MOD) != s.end()) {
                good = false;
            }
        }
        if (good) return true;
    }
    return false;
} 

int main() {
    cin >> n >> m;
    vs.resize(n, vector<long long>(m+1));
    vb.resize(n, vector<long long>(m+1));
    vector<string> s(n);
    vector<string> b(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> s[i];
    }
    for (int i = 0 ; i < n ; i++) {
        cin >> b[i];
    }

    for (int i = 0 ; i < n ; i++) {
        long long cur = 0;
        long long pow = 1;
        for (int j = 0 ; j < m ; j++) { 
            cur = (cur + ((s[i][j]-'A') * pow)) % MOD;
            //cout << (char) s[i][j] << " " << cur << endl;
            pow = (pow * 31) % MOD;
            vs[i][j+1] = cur;
            //cout << "vs " << i << " " << j+1 << " " << cur << endl;
        }
        //cout << endl;
    }

    for (int i = 0 ; i < n ; i++) {
        long long cur = 0;
        long long pow = 1;
        for (int j = 0 ; j < m ; j++) { 
            cur = (cur + ((b[i][j]-'A') * pow)) % MOD;
            pow = (pow * 31) % MOD;
            //cout << "vb " << i << " " << j+1 << " " << cur << endl;
            vb[i][j+1] = cur;
        }
        //cout << endl;
    }

    int high = m;
    int low = 1;
    int ans = 0;
    while (high >= low) {
        int mid = low + (high - low)/2;
        //cout << mid << endl;
        if (go(mid)) {
            ans = mid;
            high = mid-1;
            //cout << "good";
        } else {
            low = mid+1;
            //cout << "no good";
        }
        //cout << endl;
    }
    cout << ans << endl;
}