// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/701/C

#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

string letters = "abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int cnum(char i) {
    if (islower(i)) {
        return i - 'a';
    } else {
        return i - 'A' + 26;
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    
    //initial;
    set<int> st;
    for (int i = 0 ; i < n ; i ++) {
        st.insert(s[i]);
    }

    int r = 0;
    set<int> cur;
    int found[52] = {0};
    int next = 0;
    int ans = INT_MAX;
    int len = 0;
    bool done = false;
    for (int i = 0 ; i < n ; i ++) {
        while (cur != st && next < n) {
            cur.insert(s[next]);
            found[cnum(s[next])]++;
            next++;
            len++;
            if (cur == st) break;
        }
        if (cur != st) {
            break;
        }
        ans = min(ans,len);
        if (--found[cnum(s[i])] == 0) {
            cur.erase(s[i]);
        }
        len--;
    }
    cout << ans;

    

}