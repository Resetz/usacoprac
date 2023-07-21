#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, K;
    int N = 100000;
    cin >> n >> K;
    K--;
    vector<pair<int,int>> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].first--;
        v[i].second--;
    }
    sort(v.begin(), v.end());

    vector<vector<int>> ne(8,vector<int>(n, n+1));
    vector<vector<int>> pf(8,vector<int>(n+1, 0));
    vector<vector<int>> pr(8,vector<int>(n, -1));

    /*
    cout << endl;
    for (int i = 0 ; i < n ; i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << endl;
    */
    int cur = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < 8 ; j++) {
            pf[j][i] = pf[j][i-1];
            if (v[i].second == j) {
                pr[j][i] = i;
                pf[j][i]++;
            } else {
                pr[j][i] = (i == 0 ? -1 : pr[j][i-1]);
            }
        }
    }
    for (int i = n-1 ; i >= 0 ; i--) {
        for (int j = 0 ; j < 8 ; j++) {
            if (v[i].second == j) {
                ne[j][i] = i;
            } else {
                ne[j][i] = (i == n-1 ? n+1 : ne[j][i+1]);
            }
        }
    }

    /*
    for (int i = 0 ; i < 8 ; i++) {
        for (int j = 0 ; j < 10 ; j++) {
            cout << pf[i][j] << " ";
        }
        cout << endl;
    }*/
   // cout << "precomp finished" << endl;
    int ans = -1;
    map<vector<int>, int> m;
    vector<int> z = {0,0,0,0,0,0,0,0}; m[z] = v[0].first;
    for (int i = 0 ; i < n ; i++) {
        vector<int> order;
        vector<int> vis(8);
        int mn = 0;
        int val = 0;
        int earl = n;
        for (int j = 0 ; j < 8 ; j++) {
            mn = n;
            for (int k = 0 ; k < 8 ; k++) {
                if (!vis[k] && ne[k][i] < mn) {
                    val = k;
                    mn = ne[k][i];
                }
            }

            if (mn == n) break;
            order.push_back(val);
            vis[val] = true;
            earl = min(earl, val);
            val = -1;
        }

        vector<int> cur(8);
        for (int j = 0 ; j < 8 ; j++) {
            cur[j] = pf[j][i];
        }
        /*if (i < 10) {
            cout << "order: ";
            for (int i = 0 ; i < order.size() ; i++) {
                cout << order[i] << " ";
            }
            cout << endl;
            cout << order.size() << endl;
        }*/
        /*if (i < 10) {
            cout << i << ": ";
            for (int k = 0 ; k < 8 ; k++) {
                cout << cur[k] << " ";
            }
            cout << endl;
        }*/

        //cout << "earl: " << earl << endl;
        for (int k = 0 ; k < order.size() ; k++) {
            if (k >= K) {
                if (m.find(cur) != m.end()) {
                    m[cur] = min(m[cur], i);
                } else {
                    m[cur] = i;
                }
            }

            cur[order[k]] = pf[order[k]][i] - pf[earl][i];

            if (k >= K) {
                if (m.find(cur) != m.end()) {
                    m[cur] = min(m[cur], i);
                } else {
                    m[cur] = i;
                }
            }

            /*if (i < 10) {
                cout << v[i].first << ": ";
                for (int k = 0 ; k < 8 ; k++) {
                    cout << cur[k] << " ";
                }
                cout << endl;
            }*/
        }
        

    }

    //cout << "CALC R" << endl;
    for (int i = n-1 ; i >= 0 ; i--) {
        vector<int> order;
        vector<int> vis(8);
        int mx = -1;
        int val = 0;
        int earl = n;
        for (int j = 0 ; j < 8 ; j++) {
            mx = -1;
            for (int k = 0 ; k < 8 ; k++) {
                if (!vis[k] && pr[k][i] > mx) {
                    val = k;
                    mx = pr[k][i];
                }
            }

            if (mx == -1) break;
            order.push_back(val);
            earl = min(val, earl);
            vis[val] = true;
            val = -1;
        }

        vector<int> cur(8);
        for (int j = 0 ; j < 8 ; j++) {
            cur[j] = pf[j][i];
        }
        
        /*if (i < 10) {
            cout << "order: ";
            for (int i = 0 ; i < order.size() ; i++) {
                cout << order[i] << " ";
            }
            cout << endl;
            cout << order.size() << endl;
        }
        
    
        if (i < 10) {
            cout << i << ": ";
            for (int k = 0 ; k < 8 ; k++) {
                cout << cur[k] << " ";
            }
            cout << endl;
        }
        */
        
        //cout << "earl: " << earl << endl;
        for (int k = 0 ; k < order.size() ; k++) {
            if (k >= K) {
                if (m.find(cur) != m.end()) {
                    ans = max(ans, v[i].first - v[m[cur]+1].first);
                    //cout << "res: " << m[cur] << endl;
                }
            }
            cur[order[k]] = pf[order[k]][i] - pf[earl][i];
            if (k >= K) {
                if (m.find(cur) != m.end()) {
                    ans = max(ans, v[i].first - v[m[cur]+1].first);
                    //cout << "res: " << m[cur] << endl;
                }
            }
            
            /*if (i < 10) {
                cout << i << ": ";
                for (int k = 0 ; k < 8 ; k++) {
                    cout << cur[k] << " ";
                }
                cout << endl;
            }*/
            
        }
        
    }
    cout << ans << endl;
}