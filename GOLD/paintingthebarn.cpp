#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int,pair<int,int>>> v;
    for (int i = 0 ; i < n ; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        //a--; b--; c--; d--;
        v.push_back({a, {b, d+1}});
        v.push_back({c+1, {d+1, b}});
    }

    sort(v.begin(), v.end());

    vector<int> pf(201, 0);
    int cur = 0;
    int ans = 0;
    
    for (int i = 0 ; i < n*2 ; i++) {

        cout << i << " " << v[i].second.first << " " << v[i].second.second << endl;
    }

    for (int i = 0 ; i < 200 ; i++) {
        //cout << i << " " << v[cur].first << endl;

        //go!
        while (cur < n*2 && v[cur].first <= i) {
            pf[v[cur].second.first] += 1;
            pf[v[cur].second.second] -= 1;
            cur++;
        }

        for (int i = 0 ; i < 10 ; i++) {
            cout << pf[i];
        }
        cout << endl;

        int k = 0;
        for (int j = 0 ; j < 201; j++) {
            k += pf[j];
            if (k == m) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}