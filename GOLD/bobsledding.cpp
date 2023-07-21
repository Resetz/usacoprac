#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

int main() {
    int l,n;
    cin >> l >> n;

    vector<pair<int,int>> v(n);
    map<int,int> m;
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());
    v.push_back({l,l+1});
    stack<pair<int,int>> s;
    s.push({0, 1});
    vector<int> cur(n+1);
    for (int i = 0 ; i < n ; i++) {
        m[v[i].first] = i;
    }

    int ans = 1;
    for (int i = 0; i < n+1 ; i++) {
        pair<int,int> p = v[i];
        //cout << p.first << " " << p.second << endl;
        while (!s.empty()) {
            pair<int,int> q = s.top();
            if (p.first - q.first < q.second - p.second) {
                // cout << "popped " << cur[m[q.first]] << " " << m[q.first] << endl;
                cur[m[q.first]] = -1;
                s.pop();
            }  else {
                break;
            }
        }
        pair<int,int> q = s.top();
        p.second = min(p.second, (p.first - q.first) + q.second);
        cur[i] = (p.first - q.first - q.second + p.second)/2 + q.second;
        s.push(p);
    }
    pair<int,int> q = s.top();
    for (int i = 0; i < n+1 ; i++) {
        ans = max(ans, cur[i]);
    }
    cout << ans << endl;

}