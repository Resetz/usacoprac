#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    map<int,int> m;

    int n;
    int k = 0;
    cin >> n;
    vector<pair<pair<int,int>,int>> v;
    for (int i = 0 ; i < n ; i++) {
        int type;
        cin >> type;
        if (type == 1)  {
            int num1;
            cin >> num1;
            v.push_back({{type,num1},0});
            k++;
        } else {
            int num1, num2;
            cin >> num1 >> num2;
            v.push_back({{type,num1}, num2});
        }
    }
    vector<int> ans;
    for (int i = n-1 ; i >= 0 ; i--) {
        if (m.find(v[i].first.second) == m.end()) {
            m[v[i].first.second] = v[i].first.second;
        }

        if (v[i].first.first == 1) {
            ans.push_back(m[v[i].first.second]);
        } else {
            if (m.find(v[i].second) == m.end()) m[v[i].second] = v[i].second;
            m[v[i].first.second] = m[v[i].second];
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0 ; i < ans.size() ; i ++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}