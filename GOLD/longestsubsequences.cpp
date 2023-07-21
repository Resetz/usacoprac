#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n,a,b; cin >> n >> a >> b;
    if (n == 1 && a == 1 && b == 1) {
        cout << "1" << endl;
        return 0;
    }
    if (a*b >= n && a+b <= n+1) {
        vector<int> ans(n);
        int space = n-(a-1)-b;
        int next = 1;
        if (a == 1) {
            if (b != n) {
                cout << -1 << endl;
                return 0;
            }
            for (int i = n-1 ; i >= 0 ; i--) {
                ans[i] = next++;
            }
        } else if (b == 1) {
            if (a != n) {
                cout << -1 << endl;
                return 0;
            }
            for (int i = 0 ; i < n ; i++) {
                ans[i] = next++;
            }
        } else {
            for (int i = 0 ; i < n ; i++)
        }
        for (int i = 0 ; i < n ; i++) {
            cout << ans[i] << " ";
        }
        //checker

        cout << endl;
    } else  {
        cout << -1 << endl;
    }
}