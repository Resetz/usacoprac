#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) cin >> v[i];

    int l,r;
    r = -1;
    if (v[0] == n) {
        for (int i = n-1 ; i >= 1 ; i--) {
            if (v[i] == n-1) {
                r = i;
                l = i-2;
                break;
            }
        }
    } else {
        for (int i = n-1 ; i >= 0 ; i--) {
            if (r == -1) {
                if (v[i] == n) {
                    r = i;
                    l = i-2;
                    i--;
                }
            } else {
                if (v[l] < v[0]) {
                    l = i;
                    break;
                }
            }
        }
    }
    for (int i = r ; i < n ; i++) {
        cout << v[i] << " ";
    }
    for (int i = r-1 ; i > l ; i--) {
        cout << v[i] << " ";
    }
    for (int i = 0 ; i <= l ; i++) {
        cout << v[i] << " ";
    } 
    cout << endl;
    
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}