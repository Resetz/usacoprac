#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
string tree = "";
int found[100000] = {0};
vector<vector<int>> adj;

int l = 0;

void find(int k) {
    queue<int> q;
    char go = tree[k];
    q.push(k);

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        if (found[num] != -1 || tree[num] != go) {
            continue;
        }

        found[num] = l;
        for (int i = 0 ; i < adj[num].size() ; i++) {
            q.push(adj[num][i]);
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> tree;

    adj.resize(n);
    for (int i = 0 ; i < n-1 ; i++) {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    for (int i = 0 ; i < n ; i++) {
        found[i] = -1;
    }
    for (int i = 0 ; i < n; i++) {
        if (found[i] == -1) find(i);
        l++;
    } 

    for (int i = 0 ; i < m ; i++) {
        int f, t;
        char type;
        cin >> f >> t;
        cin >> type;
        f--; t--;
        if (found[f] == found[t] && tree[f] != type) {
            cout << 0;
            continue;
        }
        cout << 1;
    }
    cout << endl;
}