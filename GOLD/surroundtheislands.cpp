#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<vector<int>> fw(n, vector<int>(n, INT_MAX));
    for (int i = 0 ; i < n ; i++) {
        int f,t;
        cin >> f >> t;
        f--; t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> fw[i][j];
        }
    }

    vector<int> comp(n, -1);
    int nc = 0;
    queue<int> q;
    for (int i = 0 ; i < n ; i++) {
        if (comp[i] == -1) {
            //cout << nc << ": " << endl;
            q.push(i);
            comp[i] = nc;
            while (q.size() > 0) {
                int o = q.front();
                q.pop();
               // cout << o << ", ";

                for (int j = 0 ; j < adj[o].size() ; j++) {
                    if (comp[adj[o][j]] == -1) {
                        comp[adj[o][j]] = nc;
                        q.push(adj[o][j]);
                    }
                }
            }
            nc++;
            //cout << endl;
        }
    }
    //cout << "here" << endl;
    if (nc == 1) {
        cout << 0;
        return 1;
    }

    vector<vector<int>> distcomp(nc, vector<int>(nc, INT_MAX));

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            //cout << i << "-" << j << ": " << comp[i] << " " << comp[j] << " " << fw[i][j] << endl;
            distcomp[comp[i]][comp[j]] = min(distcomp[comp[i]][comp[j]], fw[i][j]);
        }
    }

    long long ans = LLONG_MAX;
    for (int i = 0 ; i < nc; i++) {
        long long sum = 0;
        for (int j = 0 ; j < nc ; j++) {
            if (i == j) continue;
            sum += distcomp[i][j]*2;
        }
        ans = min(sum, ans);
    }
    cout << ans << endl;
}