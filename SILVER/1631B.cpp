#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n ; i++) {
        cin >> v[i];
    }


    int pre = 0;
    int x = 1;
    int l = 0;
    int f = 0;
    int ans = 0;
    for (int i = n-2 ; i >= 0 ; i--) {
        if (v[i] == v[n-1]) {
            if (f == 0) {
                pre++;
                l--;    
            }
        }
        else {
            f++;
        }
        l++;
        if (l == pre+x || i == 0) {
            if (f != 0) {
                ans++;
                f = 0;
            }  
            x += l;
            x += pre;
            l = 0;
            pre = 0;
        }
    }
    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();    
}