#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,bool>> v(n);
    vector<int> pf(n+1, 0);
    for (int i = 0; i < n ; i++) {
        char c;
        cin >> v[i].first >> c;
        v[i].second = c == 'S';
    } 
    sort(v.begin(), v.end());
    for (int i = 0 ; i < n ; i++) {
        pf[i+1] = pf[i] + v[i].second*2-1;
        //cout << v[i].first << " " << v[i].second << endl;
    }
    //cout << endl;
    vector<int> last(n+1, 0);
    vector<vector<pair<int,int>>> p(2, vector<pair<int,int>>());
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {

        if (p[pf[i] & 1].size() == 0 || p[pf[i] & 1][p[pf[i] & 1].size()-1].first < pf[i]) {
            p[pf[i] & 1].push_back({pf[i], v[i].first});
        }
        //cout << v[i].first << " " << pf[i] << " " << p[pf[i] & 1].size() << endl;
        vector<pair<int,int>>::iterator vi;
        if ((vi = lower_bound(p[pf[i+1] & 1].begin(), p[pf[i+1] & 1].end(), pair<int,int>{pf[i+1], -1})) != p[pf[i+1] & 1].end()) {
            //cout << v[i].first << " " << (*vi).second << " " << v[i].first - (*vi).second << endl;
            ans = max(v[i].first - (*vi).second, ans);
        }
    }
    /*
    for (int i = 0 ; i < p[0].size() ; i++) {
        cout << p[0][i].first << " " << p[0][i].second << endl;
    }
    cout << " -" << endl;
    for (int i = 0 ; i < p[1].size() ; i++) {
        cout << p[1][i].first << " " << p[1][i].second << endl;
    }*/
    cout << ans << endl;
}