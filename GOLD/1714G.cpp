#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> ans;
vector<long long> path;
vector<vector<pair<int,pair<long long, long long>>>> v;
long long sum = 0;
int nxt = 0;
void dfs(int cur) {
    //cout << cur << " " << bsum << " " << sum << endl;
    nxt = upper_bound(path.begin(), path.end(), sum) - path.begin();
    
    ans[cur] = nxt;
    int prev = nxt;
    long long prevsum = sum;
    for (int i = 0 ; i < v[cur].size() ; i++) {
        path.push_back(path.back() + v[cur][i].second.second);

        sum += v[cur][i].second.first;
        dfs(v[cur][i].first);

        nxt = prev;
        sum = prevsum;
        path.pop_back();
    }
}

void solve(){ 
    int n;
    cin >> n;
    v.clear();
    v.resize(n, vector<pair<int,pair<long long, long long>>>());
    for (int i = 1 ; i < n ; i++) {
        int t,a,b;
        cin >> t >> a >> b;
        t--;
        v[t].push_back({i, {a,b}});
    }

    nxt = 0;
    sum = 0;
    path.clear();
    path.push_back(0);
    //cout << "dfs" << endl;
    ans.resize(n, 0);
    dfs(0);
    for (int i = 1 ; i < n ; i++) {
        cout << ans[i]-1 << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}