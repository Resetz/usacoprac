#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n ; i++) {
        cin >> v[i];
    }

    priority_queue<pair<long long,int>> pq;
    
    pq.push({0,0});
    long long ans = 0;
    vector<int> vis(n, 0);
    vector<long long> cur(n, 0);
    while (pq.size() > 0) {
        pair<long long,int> p = pq.top();
        pq.pop();

        if (vis[p.second]) {continue;}
        //cout << p.second << p.first << endl;
        ans += p.first;
        vis[p.second] = true;
        for (int i = 0 ; i < n ; i++) {
            if (!vis[i] && ((v[i]^v[p.second]) > cur[i]))) {
                cur[i] = v[i]^v[p.second];
                pq.push(pair<long long,int>{v[i]^v[p.second], i});
            }
        }
    }
    cout << ans << endl;
}