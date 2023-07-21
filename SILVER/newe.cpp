#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<vector<int>> adj(n, vector<int>());

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    for (int i = 0 ; i < n ; i++) {
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
    vector<int> vis(n);
}