#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

int main() {
    vector<pair<int,int>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(pair<int,int>(a,b));
    }
    sort(v.begin(), v.end());

    vector<int> minb(n);
    minb[0] = v[0].second;
    vector<int> maxb(n);
    maxb[n-1] = v[n-1].second;
    for (int i = 1 ; i < n ; i++) {
        minb[i] = min(minb[i-1], v[i].second);
    }
    for (int i = n-2 ; i >= 0 ; i--) {
        maxb[i] = max(maxb[i+1], v[i].second);
    }
    int ans = 1;
    for (int i = 0 ; i < n ; i++) {
        if (minb[i] > maxb[i+1]) {
            ans++;
        }
    }
    cout << ans << endl;
}