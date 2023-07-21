#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct {
    bool blue_initial;
    int rem_time;
    int s1,s2;
} node;

bool is_blue_at_time(int time, node e) {
    if (time - e.rem_time < 0) {
        return e.blue_initial;
    } else {
        if ((time - e.rem_time) % (e.s1 + e.s2) < e.s1) {
            return !e.blue_initial;
        } else {
            return e.blue_initial;
        }
    }
}
int main() {
    int s,d;
    int n,m;
    cin >> s >> d >> n >> m;
    s--;d--;

    vector<node> v(n);
    for (int i = 0 ; i < n ; i++){
        char c;
        cin >> c;
        v[i].blue_initial = c == 'B';
        cin >> v[i].rem_time >> v[i].s1 >> v[i].s2;
        if (v[i].blue_initial) {
            int temp = v[i].s2;
            v[i].s2 = v[i].s1;
            v[i].s1 = temp;
        }
    }
    vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());
    for (int i = 0 ; i < m ; i++) {
        int f,t,l;
        cin >> f >> t >> l;
        f--;t--;
        adj[f].push_back({t,l});
        adj[t].push_back({f,l});
    }

    priority_queue<pair<int, int>> pq;
    pq.push(pair<int, int>{0, s});

    vector<int> visited(n);

    while (pq.size() > 0) {
        pair<int,int> p = pq.top();
        pq.pop();

        if (visited[p.second]) continue;
        visited[p.second] = true;
        if (p.second == d) {
            cout << -p.first << endl;
            return 0;
        }
        p.first = -p.first;
        for (int i = 0 ; i < adj[p.second].size() ; i++) {
            int other = adj[p.second][i].first;
            if (!visited[other]) {
                for (int j = 0 ; j < 500 ; j++) {
                    if (is_blue_at_time(p.first+j, v[p.second]) == is_blue_at_time(p.first+j, v[other])) {
                        pq.push(pair<int,int>{-(p.first+j+adj[p.second][i].second), other});
                        break;
                    }
                }
            }
        }
    }
    cout << 0 << endl;
}