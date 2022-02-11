#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    unsigned long long n, k, x;
    cin >> n >> k >> x;
    x--;

    vector<unsigned long long> chars(1, 1);
    char last = 0;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    string ans;

    int i = 0;
    while (i < n) {
        unsigned long long cur = 0;
        if (s[i] == 'a') {
            ans.push_back('a');
            i++;
            continue;
        }
        while ( s[i] == '*' && i < n) {
            cur += k;
            i++;
        }
        unsigned long long amt = x % (cur+1);
        for (int j = 0 ; j < amt ; j++) {
            ans.push_back('b');
        }
        x /= cur+1;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

}

int main() {
    int n;
    cin >> n;
    while (n--) solve(); 
}