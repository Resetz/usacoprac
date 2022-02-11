#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;

vector<int> ans;

int solve(int cur) {
    int sum = 0;
    if (adj[cur].size() == 0) {
        ans[cur] = 0;
        return 1;
    }
    else {
        for (int i = 0 ; i < adj[cur].size() ; i++) {
            sum += solve(adj[cur][i]);
        }
        ans[cur] = sum;
        return sum+1;
    }

}

int main() {
    int n;
    cin >> n;

    adj.resize(n, vector<int>(0));
    for (int i = 1 ; i < n ; i++) {
        int to;
        cin >> to;
        to--;
        adj[to].push_back(i);
    }

    ans.resize(n);
    solve(0);
    for (int i = 0; i < n ; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}