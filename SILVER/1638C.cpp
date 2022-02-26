#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<bool> next(n, true);
    vector<int> v(n);
    stack<pair<int,int>> s;

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    s.push({v[0], v[0]}); // high low

    for (int i = 1 ; i < n ; i++) {
        pair<int,int> cur = {v[i],v[i]};
        while (s.size() > 0) {
            if (s.top().first > cur.second) {
                cur = {max(s.top().first, cur.first), min(s.top().first, cur.second)}; 
                s.pop();
            } else {
                break;
            }
        }
        s.push(cur);
    }
    cout << s.size() << endl;

}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}