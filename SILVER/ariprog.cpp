/*
ID: vincent97
TASK: ariprog
LANG: C++
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {

    #ifndef LOCAL
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<int> v;
    vector<bool> s(m*m*2, false);
    for (int i = 0 ; i <= m ; i++) {
        for (int j = i ; j <= m ; j++) {
            if (!s[i*i+j*j]) {
                v.push_back(i*i+j*j);
                s[i*i+j*j] = true;
                
            }
        }
    }

    sort(v.begin(), v.end());

    vector<pair<int,int>> sol;
    for (int i = 0 ; i < v.size() ; i++) {
        for (int j = i+1 ; j < v.size() ; j++) {
            int diff = v[j] - v[i];
            bool good = true;
            for (int k = 0 ; k < n ; k++) {
                if (!s[v[i]+diff*k] || v[i]+diff*k > v[v.size()-1]) {
                    good = false; 
                    break;
                }
            }
            if (good) sol.push_back({diff, v[i]});
        }
    }
    sort(sol.begin(), sol.end());

    for (int i = 0 ; i < sol.size() ; i++) {
        cout << sol[i].second << " " << sol[i].first << endl;
    }
    if (sol.size() == 0) {
        cout << "NONE" << endl;
    }
}