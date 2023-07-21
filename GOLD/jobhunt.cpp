#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int  D, P, C, F, S;
    cin >> D >> P >> C >> F >> S;
    vector<vector<int>> v(C, vector<int>(C, 0));
    vector<pair<pair<int,int>, int>> e;
    for (int i = 0 ; i < P ; i++) {
        int f,t;
        cin >> f >> t; f--;t--;
        v[f][t] = -D;
        e.push_back({{f,t},-D});
    }

    for (int j = 0 ; j < F ; j++) {
        int f,t,c;
        cin >> f >> t >> c; f--;t--;
        v[f][t] = c-D;
        e.push_back({{f,t},c-D});
    }

    vector<int> d(C,INT_MAX);
    d[S-1] = 0;

    for (int i = 0; i < C-1; i++) {
        for (int j = 0 ; j < e.size() ; j++) {
            if (d[e[j].first.first] + e[j].second < d[e[j].first.second]) {
                d[e[j].first.second] = d[e[j].first.first] + e[j].second;
            }
        }
    }
    for (int i = 0 ; i < e.size() ; i++) {
        if (d[e[i].first.first] + e[i].second < d[e[i].first.second]) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    int ans = 0;
    for (int i = 0 ; i < C; i++) {
        ans = min(d[i], ans);
    }
    cout << -ans+D << endl;

}