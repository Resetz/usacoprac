#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
int n, k;
vector<int> v;


void dfs(int pos, int cur) {
    if (cur < k)  {
        dfs()
    }
}

int main() {
    cin >> n >> k;
    v.resize(n+1);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i+1];
    }
    v[0] = 0;
    dfs(0,0);
    cout << ans << endl;
    
}