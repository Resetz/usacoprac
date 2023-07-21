#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int di[] = {-3,-2,-2,-1,-1,-1,0,0,0,0,1,1,1,2,2,3};
int dj[] = {0,1,-1,2,0,-2,3,1,-1,-3,2,0,-2,1,-1,0};

int main() {
    unsigned long long n,t;
    cin >> n >> t;


    vector<vector<unsigned long long>> v(n, vector<unsigned long long>(n));
    for (unsigned long long i = 0 ; i < n ; i++) {
        for (unsigned long long j = 0 ; j < n ; j++) {
            cin >> v[i][j];
        }
    }

    priority_queue<pair<unsigned long long, pair<int,int>>> pq;
    pq.push(pair<unsigned long long,pair<int,int>>{0,{0,0}});
    vector<vector<unsigned long long>> ans(n, vector<unsigned long long>(n, ULLONG_MAX));
    

    while (!pq.empty()) {
        pair<unsigned long long,pair<int,int>> p = pq.top();
        p.first *= -1;
        pq.pop();
        if ((n-1) - p.second.first + (n-1) - p.second.second < 3) {
            cout << p.first + t * ((n-1) - p.second.first + (n-1) - p.second.second) << endl;
            return 0;
        }
        if (ans[p.second.first][p.second.second] != -1) {
            continue;
        }
        ans[p.second.first][p.second.second] = p.first;
        for (int i = 0 ; i < 16; i++) {
            pair<int,int> nex = {p.second.first + di[i], p.second.second + dj[i]};
            if (nex.first >= 0 && nex.first < n && nex.second >= 0 && nex.second < n) {
                pq.push({-(p.first + t*3 + v[nex.first][nex.second]), nex});
            }
        }
    }
    cout << ans[n-1][n-1] << endl;
}