#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {cin >> v[i]; v[i]--;}

    vector<pair<int,int>> s(n, {-1,-1});
    vector<int> prev(n);
    int lastzero = 0;
    for (int i = 0 ; i < n ; i++) {
        if (v[i] == -1) {
            lastzero = i;
            continue;
        } 
        if (s[v[i]].first == -1) {
            s[v[i]].first = i;
            prev[v[i]] = i == 0 ? 0 : v[i-1];
        } else {
            s[v[i]].second = i;
            if (s[v[i]].first < s[prev[v[i]]].second && lastzero < s[prev[v[i]]].second) {
                cout << -1 << endl;
                return 0;
            }
        }
        s[v[i]].second = i;
    }

    sort(s.begin(), s.end());

    int total = 0;
    vector<int> up(n);
    vector<int> down(n);
    for (int i = 0 ; i < n ; i++) {
        if (s[i].first == -1) {
            continue;
        } else {
            up[s[i].first] = 1;
            down[s[i].second] = -1;
        }
    }
    int cur = 0;
    for (int i = 0 ; i < n ; i++) {
        cur += up[i];
        total = max(cur, total);
        cur += down[i];
    }
    cout << total << endl;
    /*
    int longest = 0;
    for (int i = 0 ; i < n ; i++) {
        if (s[i].first != -1) {
            longest = i;
            break;
        }
    }
    
    deque<pair<int, int>> dq;
    dq.push_back({0,longest});
    int total = 0;
    vector<int> vis(n, -1);
    while (dq.size() > 0) {
        pair<int,int> p = dq.front();
        dq.pop_front();

        if (vis[p.second] == -1) {
            total += p.first;
            vis[p.second] = p.first;
            pair<int,int> cur = s[p.second];
            cout << p.second << " -> " << cur.first << " " << cur.second << endl;
            for (int i = 0 ; i < n ; i++) {
                if (vis[i] != -1 || s[i].first == -1) continue;
                if (s[i].second < cur.first || s[i].first > cur.second) {
                    dq.push_front({0, i});
                } else {
                    dq.push_back({1, i});
                }
            }
        }
    }
    */

}