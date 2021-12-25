#include <iostream>
#include <vector>
#include <set>

using namespace std;

int pf[10001][10001];

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,bool>>> v;

    v.resize(m);

    set<int> l;
    set<int> g;
    for (int i = 0 ; i < n ; i++) {
        int f, t;
        cin >> f >> t;
        v[f].push_back({i, true});
        v[t].push_back({i, false});
        g.insert(t);
    }


    for (int i = 0 ; i <= m ; i++) {
        for (int j = 0 ; j < v[i].size() ; j++) {
            if (v[i][j].second) {
                l.insert(v[i][j].first);
            } else {
                g.erase(v[i][j].first);
                l.erase(v[i][j].first);
            }
        }
        set<int> tempg = g;

        int j = i;
        while (tempg.size() > 0) {
            for (int k = 0 ; k < v[j].size() ; k++) {
                if (v[i][j])
            }
            j++;
        }

        for (int j = i ; j <= m ; j++) 
        {
            
        }
    }

}