#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define dist(a, b) ((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second))
#define umin(a, b) (a == -1 ? b : min(a,b))

int main() {
    long long h, g;
    cin >> h >> g;

    vector<pair<long long,long long>> H(h+2);
    vector<pair<long long,long long>> G(g+2);


    for (long long i = 0 ; i < h ; i++) {
        cin >> H[i+1].first >> H[i+1].second;
    }

    for (long long i = 0 ; i < g ; i++) {
        cin >> G[i+1].first >> G[i+1].second;
    }

    //vector<vector<vector<long long>>> dp(h+2, vector<vector<long long>>(g+2, vector<long long>(2, -1)));
    

    vector<vector<long long>> cur(g+2, vector<long long>(2, -1));
    vector<vector<long long>> dp(g+2, vector<long long>(2, -1));
    dp[0][0] = 0;

    for (long long i = 1 ; i <= h ; i++) {
        for (long long j = 0 ; j <= g ; j++) {
            //cout << i << " " << j << " | " << dp[j][0] << " " << dp[j][1] << endl;
            for (long long k = 0 ; k <= 1; k++) {
                //current type of polong long is k

                long long kk = (k+1) % 2;
                if (dp[j][k] == -1) continue;
                //cout << " k = " << k << endl;
                if (k == 0) {
                    cur[j][k] = umin(cur[j][k], dp[j][k] + dist(H[i+1], H[i]));
                    dp[j+1][kk] = umin(dp[j+1][kk], dp[j][k] + dist(G[j+1], H[i]));
                } else {
                    dp[j+1][k] = umin(dp[j+1][k], dp[j][k] + dist(G[j+1], G[j]));
                    cur[j][kk] = umin(cur[j][kk], dp[j][k] + dist(H[i+1], G[j]));
                    
                }
            }
            
        }
        if (i == h) {
            cout << dp[g][0] << endl;
            return 0;
        }
        dp = cur;
        for (int j = 0 ; j <= g; j++) for (int k = 0; k <= 1; k++) cur[j][k] = -1;
    }
}