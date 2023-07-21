#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int bracket;
    int o = 0;
    int curind = -1;
    int curcase = s[0];
    for (int i = 1; i < n ; i++) {
        if (curcase == '(') {
            o++;
            curind = i;
            curcase = 0;
        } else if (curcase == ')') {
            if (s[i] == ')') {
                o++;
                curind = i;
                curcase = 0;
            } 
        } else {
            curcase = s[i];
        }
    }
    cout << o << " " << n-curind-1 << endl;
}

int main () {
    int n;
    cin >> n;
    while (n--) solve();
}