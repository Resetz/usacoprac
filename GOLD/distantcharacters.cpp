#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
int di[4] = {0,0,-1,1};
int dj[4] = {1,-1,0,0};

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<bool>> v(n, vector<bool>(n, 0));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            char c;
            cin >> c;
            v[i][j] = c == ')';
        }
    }   
    long long ans = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            priority_queue<pair<long long, pair<int,int>>> pq;
            pq.push({0,{i,j}});
            vector<vector<long long>> r(n, vector<long long>(n, LLONG_MAX));
            while (pq.size() > 0) {
                pair<long long, pair<int,int>> p = pq.top();
                p.first = -p.first;
                pq.pop();
                //cout << p.second.first << " " << p.second.second << endl;

                if (r[p.second.first][p.second.second] == LLONG_MAX) {
                    r[p.second.first][p.second.second] = p.first;
                    for (int i = 0 ; i < 4; i++) {
                        int newx = p.second.first + di[i];
                        int newy = p.second.second + dj[i];
                        if (newx >= 0 && newy >= 0 && newx < n && newy < n) {
                            long long dist = (v[p.second.first][p.second.second] ^ v[newx][newy]) ? b : a;
                            if (r[newx][newy] == LLONG_MAX) {
                                pq.push({-(p.first+dist), {newx,newy}});
                            }
                        }
                    }
                }
            }
            for (int k = 0 ; k < n ; k++) {
                for (int l = 0 ; l < n ; l++) {
                    ans = max(ans, r[k][l]);
                }
            }
        }
    }
    cout << ans << endl;
}