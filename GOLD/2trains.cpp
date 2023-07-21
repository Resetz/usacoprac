#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
    long long cur, cost, track, tracks_used;
} state;

class Compare
{
public:
    bool operator() (state a, state b)
    {
        if (a.cost > b.cost) {
            return true;
        } else if (a.cost == b.cost) {
            return a.tracks_used > b.tracks_used;
        } else {
            return false;
        }
    }
};
int main() {
    int a,b,k;
    cin >> a >> b >> k;
    a--; b--;
    int n = 1000;
    vector<vector<vector<int>>> adj(1000, vector<vector<int>>(1000, vector<int>()));
    vector<long long> cost(k);
    for (int i = 0 ; i < k ; i++) {
        int l;
        cin >> cost[i] >> l;
        int prev = 0;
        cin >> prev;
        prev--;
        for (int j = 0 ; j < l-1 ; j++) {
            int next;
            cin >> next;
            next--;
            adj[prev][next].push_back(i);
            //cout << prev << " " << next << " | {" << cost[i] << ", " << i << "}" << endl;
            prev = next;
        }
    }
    
    priority_queue<state, vector<state>, Compare> pq;
    pq.push(state{a, 0, -1, 0});
    vector<int> visited(1000);
    while (!pq.empty()) {
        state s = pq.top();

        pq.pop();

        if (visited[s.cur]) {continue;}
        visited[s.cur] = true;
         //cout<< "- " << s.cur << " " << s.cost << endl;
        if (s.cur == b) {
            cout << s.cost << " " << s.tracks_used << endl;
            return 0;
        }
        for (int i = 0 ; i < 1000 ; i++) {
            for (int j = 0 ; j < adj[s.cur][i].size() ; j++) {
                if (visited[i]) continue;
                state ns;
                ns.cur = i;
                ns.cost = s.cost + (s.track != adj[s.cur][i][j] ? cost[adj[s.cur][i][j]] : 0);
                ns.track = adj[s.cur][i][j];
                ns.tracks_used = s.tracks_used + 1;
                //cout << "push " << ns.cur << " " << ns.cost << " " << ns.tracks_used << " | " << s.track << " " << adj[s.cur][i].second<< endl;
                pq.push(ns);
                
            }
        }

    }
    cout << -1 << " " << -1 << endl;
}