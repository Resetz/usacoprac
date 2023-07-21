#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> v;
vector<pair<int,pair<int,int>>> queries;
vector<vector<int>> vq;
vector<vector<int>> adj;
vector<pair<int,int>> anc;

vector<int> parent;
vector<int> depth;

vector<int> current;

vector<stack<int>> seen;
vector<int> ans;

int t = 0;
int d = 1;
void adfs(int cur) {
    depth[cur] = d;
    //d++;
    anc[cur].first = t;
    t++;
    for (int i = 0 ; i < adj[cur].size() ; i++) {
        if (depth[adj[cur][i]] < 0) adfs(adj[cur][i]);
    }
    //d--;
    anc[cur].second = t-1;
    //cout << cur << " {" << anc[cur].first << ", " << anc[cur].second << "}" << endl;
}

void dfs(int cur) {
    //cout << cur << endl;
    parent[cur] = 1;
    seen[v[cur]].push(cur);
    //cout << cur << " push " << v[cur] << " " << seen[v[cur]].size() << endl;
    current.push_back(cur);
    depth[cur] = current.size()-1;
    //cout << cur << " " << current.size() << endl;
    //current[d] = cur;
    //cout << cur << " " << d << " " << current[d] << endl;;
    for (int i = 0 ; i < vq[cur].size() ; i++) {
        pair<int,pair<int,int>> q = queries[vq[cur][i]];
        //cout << " query " << vq[cur][i] << " " << q.first << " " << q.second.first << " " << q.second.second << endl;
        if (!(seen[q.first].size() == 0)) {
            int last = seen[q.first].top();
            int other = (q.second.first == cur ? q.second.second : q.second.first);
            if (last == cur) {
                ans[vq[cur][i]] = 1;
            } else {
                //cout << last << " " << depth[last] << " " << current.size() << endl;
                last = current[depth[last]+1];
                if (!(anc[last].first <= anc[other].first && anc[last].second >= anc[other].first)) {
                    ans[vq[cur][i]] |= 1;
                } 
            }
        }
    }
    for (int i = 0 ; i < adj[cur].size() ; i++) {
        if (parent[adj[cur][i]] == 0) dfs(adj[cur][i]);
    }
    d--;
    current.pop_back();
    seen[v[cur]].pop();
    //cout << cur << " seen " << v[cur] << " " << seen[v[cur]].size() << endl;
    //cout << cur << " seen " << v[cur] << " " << seen[v[cur]].size() << endl;
}

int n, q;
int main() {

    #ifndef LOCAL

    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    #endif
    cin >> n >> q;

    v.resize(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
        v[i]--;
    }
    
    parent.resize(n, -1);
    adj.resize(n);
    for (int i = 0 ; i < n-1 ; i++) {
        int f,t; cin >> f >> t; f--; t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
        parent[t] = f;
    }

    int root;
    for (int i = 0 ; i < n ; i++) {
        if (parent[i] == -1) {
            root = i;
            break;
        }
    }
    
    queries.resize(n);
    vq.resize(n);
    for (int i = 0 ; i < q ; i++) {
        int f,t,l;
        cin >> f >> t >> l;
        f--;t--;
        l--;
        vq[f].push_back(i);
        vq[t].push_back(i);
        queries[i] = {l,{f,t}};
    }

    anc.resize(n);
    depth.resize(n, -1);
    adfs(0);
    //cout << "here" << endl;

    //begin our dfs
    seen.resize(n);
    ans.resize(q);
    for (int i = 0 ; i < n ; i++) {
        parent[i] = 0;
    }
    dfs(0);
    for (int i = 0 ; i < q ; i++) {
        cout << ans[i];
    }
    cout << endl;

}