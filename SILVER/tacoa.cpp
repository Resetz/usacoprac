#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int prev = 0;
    stack<char> q;
    for (int i = 0 ; i < s.size(); i++) {
        if (q.size() > 0 && q.top() == '0' && s[i] == '1') {
            q.pop();
        } else {
            q.push(s[i]);
        }
    }
    string ans;
    while (q.size() > 0) {
        ans.push_back(q.top());
        q.pop();
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}