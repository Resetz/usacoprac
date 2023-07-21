#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//dsu data structure 
class dsu {
    public:
    vector<int> parent;
    vector<int> s;
    int size = 0;
    int setsmerged = 0;
    dsu(int n) {
        parent.resize(n);
        s.resize(n, 1);
        size = n;
        for (int i = 0 ; i < n ; i++) parent[i] = i;
    }

    int find_set(int a) {
        if (a == parent[a])
            return a;
        return parent[a] = find_set(parent[a]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (s[a] < s[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            s[a] += s[b];
            //cout << a << " " << b << endl;
            size--;
            setsmerged++;
        }
    }

    int find_size(int a) {
        return s[find_set(a)];
    }
};
//one big bfs dsu

typedef struct {
    int node;
    int dist;
    int color;
    bool travelprev;
    vector<int> path;
} state;

typedef struct {
    int time;
    vector<int> nodes;
} merge;

int operator<(state a, state b) {
    return a.dist < b.dist;
}

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    int sets = 0;
    for (int i = 0 ; i < n ; i++) {
        char c;
        cin >> c;
        b[i] = c=='1';
        if (b[i]) sets++;
    }

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0 ; i < n-1 ; i++) {
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
    
    vector<int> prev(n, -1);
    vector<int> vis(n);
    vector<int> upd(n, false);
    vector<int> save(n, 0);
    vector<vector<int>> reach(n, vector<int>());
    int updc = 0;
    dsu d(n);
    priority_queue<state> pq;
    for (int i = 0 ; i < n ; i++) {
        if (b[i]) {
            pq.push({i, 0, i, false});
            prev[i] = -(i+1);
            upd[i] = true;
            updc++;
        }
    }
    int curtime = 1;
    while (!pq.empty()) {
        state s = pq.top();
        pq.pop();
        
        s.dist = -s.dist;
        if (s.dist > curtime) {
            //time to output;
            cout << updc + sets*curtime << endl;
            //cout << endl;
            curtime++;
            //cout << endl;
            //cout << "TIME " << curtime << endl;
            //cout << endl;
        }////
        //if (s.travelprev) cout << "! ";
        //cout << s.node << " " << s.dist << " " << s.color << " " << s.travelprev << endl;
        
        if (s.travelprev) {
            if (upd[s.node]) {
                for (int i = 0 ; i < n ; i++) {
                    int cur = s.path[i];
                    d.union_set(s.path[0], s.path[i]);
                    int col = d.find_set(s.path[i]); // they should have the same color
                    while (prev[cur] >= 0 && !upd[cur]) {
                        //cout << "v " << cur << endl;
                        pq.push({cur, 0, col, false});
                        upd[cur] = true;
                        updc++;
                        cur = prev[cur];
                    }
                    sets--;
                
                }
                cout << "merge results: " << updc << " " << sets << endl; 
            } else {
                pq.push({prev[s.node], -(s.dist+1), s.color, true, s.path});
            }
        } else {
            for (int i = 0 ; i < adj[s.node].size() ; i++) {
                if (adj[s.node][i] == prev[s.node]) continue;
               // cout << s.node << " -> " << adj[s.node][i] << endl;
                if (prev[adj[s.node][i]] >= 0) {
                    if (d.find_set(adj[s.node][i]) == d.find_set(s.node)) continue;
                    //merge right now
                    if (save[adj[s.node][i]] < curtime * reach[adj[s.node][i]].size()) {
                        pq.push({adj[s.node][i], -(s.dist+1), s.color, true, reach[adj[s.node][i]]});
                    }/*
                    int cur = adj[s.node][i];
                    d.union_set(s.node, adj[s.node][i]);
                    int col = d.find_set(s.node); // they should have the same color
                    while (prev[cur] > 0 && !upd[cur]) {
                        pq.push({cur, 0, col, false});
                        upd[cur] = true;
                        updc++;
                        cur = prev[cur];
                    }
                    sets--;
                    */
                } else {
                    if (upd[adj[s.node][i]]) {
                        pq.push({adj[s.node][i], -(s.dist+1), s.color, true, {s.node, adj[s.node][i]}});
                    } else {
                        d.union_set(s.node, adj[s.node][i]);
                        save[adj[s.node][i]] += s.dist;
                        reach[adj[s.node][i]].push_back(s.node);
                        //cout << adj[s.node][i] << " prev is now " << s.node << endl;
                        prev[adj[s.node][i]] = s.node;
                        pq.push({adj[s.node][i], -(s.dist+1), s.color, false});
                    }
                }
            }
        }
    }
    while (curtime <= n) {
        cout << updc + sets*curtime << endl;
        curtime++;
    }
}