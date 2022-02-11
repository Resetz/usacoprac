#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<pair<int,int>> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }

    vector<int> ans(s+1, 0);
    for (int i = 0 ; i < n ; i++) {
        for (int j = s-v[i].first+1 ; j >= 0; j--) {
            ans[j+v[i].first] = max(ans[j]+v[i].second, ans[j+v[i].first]);
        }
    }
    cout << ans[s] << endl;
}