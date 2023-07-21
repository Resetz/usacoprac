#include <iostream>
#include <vector>

using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    int left;
    bool b = false;
    for (left = 0; left < n/2 ; left++) {
        if (s[left] != s[n-left-1]) {
            b = true;
            break;
        }
    }
    if (b) {
        for (int i = left ; i < n-left ; i+=2) {
            if (s[i] != s[i+1]) {
                cout << "Alice" << endl;
                return;
            }
        }
    }
    cout << "Draw" << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}