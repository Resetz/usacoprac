#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i]; v[i]--;
    }

    vector<int> ans(n, -1);
    for (int i = 0 ; i < n ; i++) {
        if (ans[i] != -1) continue;
        vector<int> s;
        set<int> vis;
        int cur = i;
        while (ans[cur] == -1 && vis.insert(cur).second) {
            s.push_back(cur);
            cur = v[cur];
        }
        //cout << i << " " << s.size() << endl;
        if (ans[cur] != -1) {
            for (int j = 0 ; j < s.size() ; j++) {
                ans[s[j]] = ans[cur] + (s.size() - j);
            }
            continue;
        }

        int start = 0;
        int amt;
        for (int j = s.size()-1 ; j >= 0 ; j--) {
            if (s[j] == cur) {
                start = j;
                break;
            }
        }
        
        amt = s.size() - start;

        for (int j = s.size()-1 ; j >= 0; j--) {
            ans[s[j]] = max(amt, (int)s.size()-j);
        }
    }
    for (int i = 0 ; i < n ; i++) {
        cout << ans[i] << endl;
    }
}