#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int r,c,k;
    cin >> r >> c >> k;

    vector<vector<int>> v(r, vector<int>(c, 0));

    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < c ; j++) {
            cin >> v[i][j];
        }
    }

    vector<map<int,int>> m(c);
    vector<vector<int>> dp(r, vector<int>(c, 0));
    vector<int> pf(c, 0);
    
    dp[0][0] = 1;
    for (int i = 0 ; i < r ; i++) {
        
        for (int j = 1 ; j < c ; j++) {
            dp[i][j] = pf[j-1];
            for (int l = 0 ; l < j ; l++) {
                if (m[l].find(v[i][j]) != m[l].end()) {
                    dp[i][j] = (dp[i][j] - m[l][v[i][j]] + 1000000007) % 1000000007;

                }
            }
        }
        int cur = 0;
        for (int j = 0 ; j < c ; j++) {
            cur = (cur + dp[i][j]) % 1000000007;
            //cout << dp[i][j] << " ";
            pf[j] = (pf[j]+cur) % 1000000007;

        }
        for (int j = 0 ; j < c ; j++) {
            if (m[j].find(v[i][j]) == m[j].end()) {
                m[j][v[i][j]] = dp[i][j];
            } else {
                m[j][v[i][j]] = (m[j][v[i][j]] + dp[i][j]) % 1000000007;

            }
        }
        //cout << endl;
    }

    cout << dp[r-1][c-1] << endl;

}