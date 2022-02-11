#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int c;
    cin >> n >> c;

    vector<int> v(c);
    vector<int> v2(c);
    vector<pair<int,int>> p(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> p[i].first >> p[i].second;
        v[p[i].first]++;
        v2[p[i].second]++;
    }

    vector<pair<pair<int,int>, int>> solve(n);
    for (int i = 0 ; i < n ; i++) {
        solve[i] = {{v2[p[i].second], v[p[i].first]},i};
    }
    sort(solve.begin(), solve.end());

    int ans = 0;
    vector<bool> taken(c);
    for (int i = 0 ; i < n ; i++) {
        if (!taken[p[solve[i].second].first]) taken[p[solve[i].second].first] = true;
        else if (!taken[p[solve[i].second].second]) taken[p[solve[i].second].second] = true;
        else {ans++;}
    }
    cout << ans << endl;
    for (int i = 0 ; i < n ; i++) {
        cout << solve[i].second + 1 << endl;
    }

}