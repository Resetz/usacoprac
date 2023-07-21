#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

#define MOD 1000000007
#define MAXM 100000

bool vis[MAXM];
vector<int> E[MAXM];

pair<int, int> dfs(int x) {
  if(vis[x]) return make_pair(0, 0);
  vis[x] = true;

  pair<int, int> ret(1, E[x].size());
  for(int i = 0; i < E[x].size(); i++) {
    pair<int, int> res = dfs(E[x][i]);
    ret.first += res.first;
    ret.second += res.second;
  }
  return ret;
}

int main() {
  int N, M;
  cin >> N >> M;

  for(int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  int result = 1;
  for(int i = 0; i < N; i++) {
    if(vis[i] || E[i].empty()) continue;

    pair<int, int> res = dfs(i);
    if(res.second % 2) cerr << "PROBLEM" << endl;
    res.second /= 2;
    if(res.first == res.second + 1) {
      result = (1ll * result * res.first) % MOD;
    } else if(res.first == res.second) {
      result = (2 * result) % MOD;
    } else {
      result = 0;
    }
  }

  cout << result << endl;
}