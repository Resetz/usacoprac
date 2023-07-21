#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    #define int unsigned long long
    int n,a,b;
    cin >> n >> a >> b;
    a--;b--;
    vector<int> v(n);
    for (int i = 0; i < n ; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(),v.rend());
    int ans = 0;
    for (int i = 0 ; i < b-a+1 ; i++) {
        ans += v[i];
    }
    cout << ans << endl;
}