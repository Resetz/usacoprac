#include <iostream>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<int> count(26, 0);
    for (int i = 0 ; i < s.size() ; i++) {
        count[s[i]-'a']++;
    }

    int beg = 0;
    for (int i = 0 ; i < s.size() ; i++) {
        if (count[s[i]-'a'] > 1) {
            count[s[i]-'a']--;
        } else {
            break;
        }
        beg++;
    }
    
    for (int i = beg ; i < s.size() ; i++) {
        cout << s[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}