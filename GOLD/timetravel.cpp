#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> v;
    v.push_back({-1, -1});
    int prev = 0;
    for (int i = 0 ; i < n ; i++) {
        char c;
        cin >> c;
        if (c == 'a') {
            int t;
            cin >> t;
            v.push_back({prev, t});
        } else if (c == 's') {
            if (v[prev].first != -1) v.push_back(v[v[prev].first]);
        } else {
            int t;
            cin >> t;
            t--;
            v.push_back(v[t]);
        }
        prev = i+1;
        cout << v.back().second << endl;
    }
}
/* Takeaway:
  - Look at what you need from each query and if you 
    need more data.

  - Persistent stack -> data structure where you can time
                        travel back.
*/