//  dp
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

typedef struct {
    int p,c,x;
} cow;

int main() {
    #define int long long
    int n, a, b;
    cin >> n >> a >> b;
    //dp[moonies][icecream] -> o(n^2) states -> o(n) transitions
    vector<cow> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].p >> v[i].c >> v[i].x;
    }

    vector<vector<int>> dp(a+1, vector<int>(b+1, -1));
    //vector<vector<int>> cur(a+1, vector<int>(b+1, -1));
    dp[a][b] = 0;
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        cow cur = v[i];
        for (int j = 0 ; j <= a ; j++) {
            for (int k = 0 ; k <= b ; k++) {
                if (dp[j][k] < 0) continue;
                //transition;
                int bribe = 0;
                while (cur.c - bribe >= 0 && k - bribe * cur.x >= 0) {
                    if (j - (cur.c-bribe) < 0) {
                        bribe++;
                        continue;
                    }
                    dp[j - cur.c + bribe][k - bribe * cur.x] = max(dp[j - cur.c + bribe][k - bribe * cur.x], dp[j][k] + cur.p);
                    ans = max(ans, dp[j - cur.c + bribe][k - bribe * cur.x]);
                    bribe++;
                }
            }
        }
    }
    cout << ans << endl;
}