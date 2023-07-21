#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,m,k;
    cin >> n >> m >> k;


    vector<int> r(n);
    vector<int> l(n);
    for (int i = 0 ; i < n ;i++) {
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
    }

    vector<char> s;
    for (int i = 0 ; i < m ; i++) {
        char c;
        cin >> c; s.push_back(c);
    }
    vector<int> pc(n);
    for (int i = 0 ; i < n ; i++) {
        int cur = i;
        for (int j = 0 ; j < s.size() ; j++) {
            if (s[j] == 'L') {
                cur = l[cur];
            } else {
                cur = r[cur];
            }
        }
        pc[i] = cur;
    }

    vector<int> vis(n);
    vector<int> order;
    int cur = 0;
    while (!vis[cur]) {
        order.push_back(cur);
        vis[cur] = true;
        cur = pc[cur];
    }
    int cyclestart;
    for (int i = 0; i < order.size(); ++i) {
        if (order[i] == cur) {
            cyclestart = i;
        }
    }
    int cyclesize = order.size() - cyclestart;
    cout << order[((k-cyclestart) % cyclesize)+cyclestart]+1 << endl;
}