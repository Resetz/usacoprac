#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void solve() {
    int n;cin >> n;
    string s;
    cin >> s;
    for (int i = 0 ; i < n ; i++) {
        if (s[i] == 'M' || s[i] == 'm') {
            s[i] = 0;
        }
        else if (s[i] == 'E' || s[i] == 'e') {
            s[i] = 1;
        }
        else if (s[i] == 'O' || s[i] == 'o') {
            s[i] = 2;
        }
        else if (s[i] == 'W' || s[i] == 'w') {
            s[i] = 3;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    string k = s;
    sort(k.begin(), k.end());
    
    bool good = true;
    vector<int> vis(4);
    for (int i = 0 ; i < n ; i++) {
        good &= (s[i] == k[i]);
        vis[k[i]] = true;
    }
    for (int i = 0 ; i < 4; i++) {
        good &= vis[i];
    }
    good &= (s[n-1] == 3);
    good &= (s[0] == 0);
    if (good) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}