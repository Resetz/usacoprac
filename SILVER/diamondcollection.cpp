#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    
    int n, k;
    cin >> n;

    cin >> k;

    vector<int> v;
    v.resize(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    vector<int> a;
    vector<int> b;
    a.resize(n);
    b.resize(n);
    int l = 0;
    for (int i = 0 ; i < n ; i++) {
        //cout << v[i] << " ";
        while (i+l < n && v[i+l] <= v[i]+k) l++;
        a[i] = l;
        l--;
    }

    b[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        b[i] = max(a[i], b[i+1]);
    }

    int ans = 0;
    for (int i = 0 ; i < n-1; i++) {
        ans = max(a[i] + b[i + a[i]], ans);
    }
    cout << ans << endl;
}