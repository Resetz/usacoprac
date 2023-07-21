#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<long long, long long> pll;

long long go(int r) {
    if (r == 0 || r == 1) return 0;
    vector<vector<long long>> dp(32, vector<long long>(32));
    dp[1][0] = 1; // 4 3
    long long cur = 4;
    long long k = 2;
    while (cur <= r) {
        for (int j = 0; j < 32; j++) {
            dp[k][j] += dp[k-1][j];
            if (j > 0) dp[k][j] += dp[k-1][j-1];
            if (dp[k][j] > 0) {
                //cout << k << " " << j << " = " << dp[k][j] << endl;
            }
        }
        k++;
        cur *= 2;
    }
    cur /= 2;
    long long ret = 0;
    for (int i = 1 ; i < k ; i++) {
        for (int j = (i+1)/2 ; j < i ; j++) {
            ret += dp[i][j];
            //cout << i << " " << j << " + " << dp[i][j] << endl;
        }
    }

    //cout << "dp " << k << " " << cur << endl;
    vector<vector<long long>> odp[2];
    odp[0].resize(32, vector<long long>(32));
    odp[1].resize(32, vector<long long>(32));
    int o = cur/2;
    k = 2;
    odp[1][1][0] = 1;
    while (o > 0) {
        //cout << "r " << r << " " << o << " : " << (r & o) << endl;
        for (int j = 0; j < 32 ; j++) {
            if ((r & o) > 0) {
                odp[1][k][j] += odp[1][k-1][j]; //place 1
                if (j > 0) odp[0][k][j] += odp[1][k-1][j-1];//place 0
            } else {
                if (j > 0) odp[1][k][j] += odp[1][k-1][j-1]; //place 0
            }
            if (j > 0) odp[0][k][j] += odp[0][k-1][j-1];//place 0
            odp[0][k][j] += odp[0][k-1][j];
        }
        o /= 2;
        k++;
    }
    //int temp = ret;
    for (int i = (k)/2; i < k-1; i++) {
        ret += odp[0][k-1][i];
        ret += odp[1][k-1][i];// = 1
    }
  //  cout << ret - temp << endl;
    return ret;
}
int main() {
    int l,r;
    cin >> l >> r;
    
    cout << go(r) - go(l-1) << endl;
}