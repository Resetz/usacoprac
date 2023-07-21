#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <iomanip>

using namespace std;

int n;
vector<pair<int,int>> v;
vector<vector<double>> adj;
vector<double> visited;
int cur = 1;

void ff(int k) {
    visited[k] = cur;
    for (int i = 0 ; i < n ; i++) {
        if (!visited[i] && adj[k][i]) ff(i);
    }
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0 ; i < n ; i++) cin >> v[i].first >> v[i].second;
    adj.resize(n, vector<double>(n, 0));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            char c;
            cin >> c;
            if (c == '1') {
                int x,y;
                x = v[i].first - v[j].first;
                y = v[i].second - v[j].second;
                adj[i][j] = adj[j][i] = sqrt(x*x+y*y); 
            }
        }
    }

    visited.resize(n, 0);

    for (int i = 0 ; i < n ; i++) {
        if (!visited[i]) {
            //cout << "here " << i << endl;
            ff(i);
            cur++;
        }
    }
    vector<vector<double>> dist = adj;
      for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (dist[i][j] == 0) dist[i][j] = LLONG_MAX;
        }
    }
    for (int k = 0 ; k < n ; k++) {
        for (int i = 0 ; i < n ; i++) {
            //if (i == k) continue;
            for (int j = 0 ; j < n ; j++) {
                //if (j == i || adj[i][j] == 0) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<double> worst(n, 0);
    vector<double> diameter(cur, 0);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (i == j) continue;
            if (dist[i][j] != LLONG_MAX) worst[i] = max(dist[i][j], worst[i]);
        }
        diameter[visited[i]-1] = worst[i];
    }
    double ans = 1e20;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (visited[i] == visited[j]) continue;
            int x, y;
            x = v[i].first - v[j].first;
            y = v[i].second - v[j].second;
            double temp = 0;
            temp = max(temp,worst[i]+worst[j]+sqrt(x*x+y*y));
            temp = max(temp,(double)diameter[visited[i]]);
            temp = max(temp,(double)diameter[visited[j]]);
            ans = min(ans, temp);
            //cout << ans << " " << temp << endl;
        }
    }
    cout << fixed << setprecision(6) << ans << endl;

    //find unions

}