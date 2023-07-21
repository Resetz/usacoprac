#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    for (int i = 0 ; i < n ; i++) {
        int m;
        cin >> m;
        bool good = false;
        for (int j = 0 ; j < m ; j++) {
            int c;
            cin >> c;
            if ( k > c ) {
                good = true;
            } 
        }
        if (good) ans.push_back(i+1);
    }
    cout <<ans.size() << endl;
    for (int i = 0 ; i < ans.size() ; i++) {
        cout << ans[i] << " ";
    }
}
int main() {
    solve();
}