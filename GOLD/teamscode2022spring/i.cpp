#include <iostream>
#include <vector>

using namespace std;
inline vector<int> comb(vector<int> a, vector<int> b, vector<int> c){
    vector<int> ret(32);
    for (int i = 0 ; i < 32 ; i++) {
        ret[i] = a[i] + b[i] - c[i];
    } 
    return ret;
}

inline vector<int> operator-(vector<int> a, vector<int> b) {
    vector<int> ret(a.size());
    for (int i = 0 ; i < ret.size() ; i++) ret[i] = a[i]-b[i];
    return ret;
}
inline vector<int> operator+(vector<int> a, vector<int> b) {
    vector<int> ret(a.size());
    for (int i = 0 ; i < ret.size() ; i++) ret[i] = a[i]+b[i];
    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<long long>> grid(n, vector<long long>(m));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> grid[i][j];
        }
    }
    vector<int> z(32);
    vector<vector<vector<int>>> pf(n,vector<vector<int>>(m,vector<int>(32)));
    for (int i = 0 ; i < 32 ;i++) {
        pf[0][0][i] = (grid[0][0] >> i) & 1;
    }
    for (int i = 1 ; i < m ; i++) {
        for (int j = 0 ; j < 32 ; j++) {
            pf[0][i][j] = pf[0][i-1][j]+((grid[0][i] >> j) & 1);
        }
    }
    for (int i = 1 ; i < n ; i++) {;
        for (int j = 0 ; j < 32 ; j++) {
            pf[i][0][j] = pf[i-1][0][j]+((grid[i][0] >> j) & 1);
        }
    }
    for (int i = 1 ; i < n ; i++) {
        for (int j = 1 ; j < m ; j++) {
            for (int k = 0 ; k < 32 ; k++) {
                pf[i][j][k] = pf[i-1][j][k] + pf[i][j-1][k] - pf[i-1][j-1][k] + ((grid[i][j] >> k) & 1);
            } 
        }
    }
    for (int i = 0 ; i < q ; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;b--;c--;d--;
        vector<int> cur(32);
        vector<int> l(32);
        if (a == 0) {
            l = z;
        } else {
            l = pf[a-1][d];
        }
        cur = cur-l;
        if (b == 0) {
            l = z;
        } else {
            l = pf[c][b-1];
        }
        cur = cur-l;
        if (a == 0 || b == 0) {
            l = z;
        } else {
            l = pf[a-1][b-1];
        }
        cur = cur+l;
        cur = cur+pf[c][d];
        long long ans = 0;
        long long p2 = 1;
        for (int i = 0 ; i < 32 ; i++) {
            ans += p2 * (cur[i] > 0);
            p2 *= 2;
        }
        cout << ans << endl;
    }
}