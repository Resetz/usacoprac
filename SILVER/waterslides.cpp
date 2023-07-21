#include <iostream>
#include <vector>
#include <climits>


using namespace std;

int main() {

    #define int long long
    int v, e, k;

    cin >> v >> e >> k;
    vector<vector<pair<int,int>>> adj(v, vector<pair<int, int>>());
    vector<vector<pair<int,int>>> rev(v, vector<pair<int, int>>());

    for (int i = 0 ; i < e ; i++) {
        int f, t, g;
        cin >> f >> t >> g;
        adj[f-1].push_back({t-1, g});
        rev[t-1].push_back({f-1, g});
    }

    vector<int> dp(v, -1);
    vector<int> ne(v, -1);
    dp[0] = 0;
    ne[0] = 0;
    for (int i = 0;  i < k ; i++) {
        for (int c = 0; c < v; c++) {
            if (dp[c] >= 0) {
                //cout << "dp " << c << endl;
                for (int j = 0; j < adj[c].size() ; j++) {
                    ne[adj[c][j].first] = max(dp[c]+adj[c][j].second, ne[adj[c][j].first]);
                }
            }
        }
        dp = ne;
    }

    vector<int> dpm(v, -1);
    vector<int> nem(v, -1);
    dpm[v-1] = 0;
    nem[v-1] = 0;
    for  (int i = 0; i < v ; i++) {
        for (int c = 0; c < v; c++) {
            if (dpm[c] >= 0) {
            
                for (int j = 0; j < rev[c].size() ; j++) {
                    if (nem[rev[c][j].first] == -1) {
                        nem[rev[c][j].first] = dpm[c]+rev[c][j].second;
                    } else {
                        nem[rev[c][j].first] = min(dpm[c]+rev[c][j].second, nem[rev[c][j].first]);
                    }
                }
            }
        }
        dpm = nem;
    }
    int ans = -1;
    for (int i = 0 ; i < v ; i++) {
        if (dp[i] != -1) ans = max(dp[i]+dpm[i], ans);
    }
    cout << ans << endl;
}