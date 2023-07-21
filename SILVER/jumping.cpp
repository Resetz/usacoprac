    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <climits>

    using namespace std;

    int main() {
        int n,m,q;

        cin >> n >> m >> q;
        vector<vector<int>> adj(n, vector<int>());
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0 ; i < m ; i++) {
            int f,t, a;
            cin >> f >> t >> a;
            f--; t--;

            //dist[t][f] = a;
            dist[f][t] = a;
        }


        for (int k = 0 ; k < n ; k++) {
            for (int i = 0 ; i < n ; i++) {
                if (k == i) continue;
                if (!dist[i][k]) continue;
                for (int j = 0 ; j < n ; j++) {
                    if (j == i || j == k) continue;
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
                }
            }
        }

        for (int i = 0 ; i < q ; i++) {
            int f, t;
            cin >> f >> t;
            f--; t--;
            cout << (dist[f][t] == INT_MAX ? -1 : dist[f][t]) << endl;
        }
    }