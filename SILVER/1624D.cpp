#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int charcount[26];
void solve() {
    cin >> n >> m;
    string s;
    cin >> s;

    for (int i = 0; i < 26; i++) {
        charcount[i] = 0;
    }

    for (int i = 0 ; i < s.size(); i++) {
        charcount[s[i]-'a']++;
    }


    int odd = 0;
    int pairs = 0;
    for (int i = 0 ; i < 26; i++) {
        pairs += charcount[i]/2;
        odd += charcount[i]%2;
    }
    cout << (pairs/m)*2 + (2 * (pairs % m) + odd >= m) << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}