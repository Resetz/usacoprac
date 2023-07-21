#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> rates;

pair<long long, long long> calc(int k, int c, int p) {
    long long ans = -p;
    int count = 0;
    int pk = k;
    for (int i = 0 ; i < rates.size(); i++) {
        if (k&1) {
            //// cout << "ans = " << ans << endl;
            ans += c*rates[i];
            count++;
        }
        k = (k >> 1);
    }
    return {ans, pk};
}

int main() {
    int n,m;
    cin >> n >> m;
    long long n2 = (1 << n);

    rates.resize(n);

    for (int i = 0 ; i < n ; i++) cin >> rates[i];

    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0 ; i < m ; i++) {
        int f,t,l;
        cin >> f >> t >> l;
        f--;t--;
        adj[t].push_back({f,l});
    }
    // cout << "here" << endl;
    
    vector<vector<pair<long long,pair<long long, long long>>>> p(n, vector<pair<long long, pair<long long, long long>>>(0));
    vector<vector<pair<long long ,long long>>> go(n, vector<pair<long long, long long>>(0));
    
    for (int i = 0 ; i < n ; i++) {
        vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(n2+1, {-1,-1}));
        vector<vector<pair<long long, long long>>> cur(n, vector<pair<long long, long long>>(n2+1, {-1,-1}));
        dp[i][1<<i] = {0,0};
        p[i].push_back({0,{0,1<<i}});
        for (int j = 0 ; j < n*2 ; j++) {
            //// cout << "going " << j << endl << endl;
            for (int c = 0 ; c < n ; c++) {
                for (int k = 0 ; k <= n2 ; k++) {
                    if (dp[c][k].first != -1) {
                        // cout << "ck" << c << " " << k << " " << dp[c][k].first << endl;
                        //// cout << c << " " << k << " " << dp[c][k].first << endl;
                        //go through edges
                        for (int l = 0 ; l < adj[c].size() ; l++) {
                            // cout << adj[c][l].first << endl;
                            // cout << adj[c][l].second << endl;
                            // cout << endl;
                            int t = adj[c][l].first;
                            int le = adj[c][l].second;
                            // cout << "moving " << k << " " << t << " " << (k | (1 << t)) << endl;
                            // cout << "moving " << k << " " << t << " " << (k | (1 << t)) << endl;
                            // cout << "moving " << k << " " << t << " " << (k | (1 << t)) << endl;
                            if ((k >> t) & 1) {
                                cur[t][k] = {dp[c][k].first, dp[c][k].second};
                                p[i].push_back({dp[c][k].first, calc(k, cur[t][k].first, cur[t][k].second)});
                                // cout << "toa " << t << " " << k << endl;
                            } else {
                                int nk = k | (1 << t);
                                cur[t][nk] = {dp[c][k].first + le, dp[c][k].second + (dp[c][k].first + le) * rates[t]};
                                p[i].push_back({dp[c][k].first + le, calc(nk, cur[t][nk].first, cur[t][nk].second)});
                                // cout << "tob " << t << " " << nk << " " << cur[t][nk].first << " " << cur[t][nk].second << " " << calc(nk, cur[t][nk].first, cur[t][nk].second).first << endl;
                            }
                        }
                    }
                }
            }   
            //clear cur
            for (int j = 0 ; j < n ; j++) {
                for (int k = 0 ; k < n2 ; k++) {
                    dp[j][k] = cur[j][k];
                    cur[j][k] = {-1,-1};
                }
            }
        }
        //// cout << "hasdf" << endl;
        sort(p[i].begin(), p[i].end());
        int prev = p[i][0].first;
        /*go[i].push_back(p[i][0]);

        for (int j = 1 ; j < p[i].size() ; j++) {
            // cout << "j " << j << endl << endl;
            if (p[i][j].first != prev) {
                go[i].push_back({p[i][j].first, max(p[i][j].second, go[i][go[i].size()-1].second)});
            } else {
                go[i][go.size()-1].second = max(go[i][go[i].size()-1].second, p[i][j].second);
            }
        }*/
        //// cout << "processed" << endl;
    } 
    //// cout << "here" << endl;
    int q;
    cin >> q;
    for (int i = 0 ; i < q ; i++) {
        int a,b;
        cin >> a >> b;
        b--;
        /*int low, high, ans;
        low = 0;
        high = p[b].size();
        
        while (high >= low) {
            int mid = low + (high - low) / 2;

            if (p[b][mid].first <= a) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }*/

        long long ans = 0;
        for (int j = 0 ; j < p[b].size() ; j++) {
            // cout << p[b][j].first << ", " << p[b][j].second.first << ", " << p[b][j].second.second << endl;
            if (p[b][j].first <= a) {
                long long bst = p[b][j].second.first;
                // cout << bst;
                for (int k = 0 ; k < n ; k++) {
                    if ((p[b][j].second.second >> k) & 1) {
                        bst += (a-p[b][j].first) * rates[k];
                    }
                }
                // cout << " > " << bst << endl;
                ans = max(ans, bst);
            }
        }
        cout << ans << endl;
    }
}
