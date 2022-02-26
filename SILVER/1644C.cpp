#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> dp(n+1, vector<int>(n, 0));

    vector<int> num(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> num[i];
    }
    
    
    vector<int> maxes(n+1,INT_MIN);
    maxes[0] = 0;
    for (int i = 0 ; i < n ; i++) {
        int cur = num[i];
        maxes[1] = max(cur, maxes[1]);
        for (int j = i+1 ; j < n ; j++) {
            cur += num[j];
            maxes[j-i+1] = max(cur, maxes[j-i+1]);
        }
    }


    for (int i = 0 ; i <= n ; i++) {
        int ans = 0;
        for (int j = 0 ; j <= n ; j++) {
            ans = max(maxes[j], ans);
        }
        for (int j = i+1 ; j <= n ; j++) {
            maxes[j] += k;
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}
