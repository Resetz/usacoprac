#include <iostream>
#include <vector>
#include <algorithm>

#define comp

using namespace std;

vector<int> v;
int n;
int q;

void solve() {
    int top;
    int bot;
    cin >> bot >> top;
    cout << upper_bound(v.begin(), v.end(), top) - lower_bound(v.begin(), v.end(), bot)<< endl;
}

int main() {
    #ifdef comp
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    #endif

    cin >> n >> q;
    v.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    while (q--) {
        solve();
    }
}