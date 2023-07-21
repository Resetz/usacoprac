#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;
vector<bool> taken;
vector<int> ind;
vector<vector<int>> v;
int n;
bool done = false;

void dfs(int i) {
    int j = 0;
    while (true) {
        if (!taken[v[i][j]]) {
            ans[i] = v[i][j];
            taken[v[i][j]] = true;
            if (i == n-1) {
                done = true;
                return;
            }
            dfs(i+1);
            taken[v[i][j]] = false;
            if (done) return;
        }
        if (v[i][j] == i) { break; } 
        j++;
    }
}
int main() {
    cin >> n;
    v.resize(n, vector<int>());
    ind.resize(n);
    ans.resize(n);
    taken.resize(n, false);
    for (int i = 0 ; i < n ;i++) {
        ind[i] = i;
        int k = 0;
        for (int j = 0 ; j < n ; j++) {
            cin >> k;
            if (i == k) {
                break;
            }
            v[i].push_back(j);
        }
    }

    dfs(0);
    for (int i = 0; i < n ; i++) {
        cout << ans[i]+1 << endl;
    }
}