#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef struct {
    int a,lie,order;
} edge;

int n,m;
vector<int> v;
vector<vector<edge>> adj;
vector<edge> e;

bool go(int k) {
    vector<int> marked(n, 0);
    vector<int> inc(n, 0);

    for (int i = 0 ; i < k ; i++) {
        inc[e[i].a]++;
    }

    for (int i = 0 ; i < n ; i++) {
        if (marked[i] == 0) {
            marked[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int p = q.front();
                //cout << p << " " << marked[p] << endl;
                q.pop();

                for (int j = 0 ; j < adj[p].size(); j++) {
                   //cout << p << " " << j << ": " << adj[p][j].order << endl;
                    if (adj[p][j].order < k) {
                        int next = marked[p];
                        if (adj[p][j].lie) { 
                            next--;
                            next = (next + 1) % 2;
                            next++;
                        }

                        if (marked[adj[p][j].a] == 0) {
                            marked[adj[p][j].a] = next;
                            q.push(adj[p][j].a);
                        } else if (!(marked[adj[p][j].a] == next)) {
                            //cout << p << " " << endl;
                            //cout << k << " returned false " << endl;
                            return false;
                        }
                    }
                }
            }
        }
    }
    //cout << k << " returned true " << endl;
    return true;
}

int main() {
    cin >> n >> m;

    adj.resize(n, vector<edge>());

    for (int i = 0 ; i < m ; i++) {
        int f,t;
        char c;
        cin >> f >> t >> c;
        f--;t--;
        adj[f].push_back({t, c=='L', i});
        adj[t].push_back({f, c=='L', i});
        e.push_back({t, c=='L', i});
    }

    int high = m;
    int low = 0;
    int ans;

    while (high >= low) {
        int mid = low + (high - low) / 2;
        if (go(mid)) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    cout << ans << endl;

}