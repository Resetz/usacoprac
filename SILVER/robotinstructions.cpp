#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;
    pair<long long, long long> e;
    cin >> e.first >> e.second;
    vector<pair<long long, long long>> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }

    vector<map<pair<long long, long long>, int>> maps(21);
    //cout << " " << (min(20, n)) << " " <<(1 << (min(20, n))) << endl;
    for (int j = 0 ; j < (1 << (min(20, n))) ; j++) {
        int cur = j;
        int count = 0;
        int k = 0;
        pair<long long, long long> pos = {0,0};
        for (int k = 0 ; k < n ; k++) {
            if (1 & (j >> k)) {
                pos.first += v[k].first;
                pos.second += v[k].second;
                count++;
            }
        }
        //cout << " : " << pos.first << " " << pos.second << endl;
        maps[count][pos]++;
    }
    for (int i = 1 ; i <= min(20, n); i++) {
        cout << maps[i][e] << endl;
    }
    vector<long long> ans(20);
    for (int i = 0 ; i < (1 << max(0,(min(0,n-20)))) ; i++) {
        int cur = i;
        int count = 0;
        int k = 0;
        pair<long long, long long> pos = {0,0};
        for (int k = 0 ; (i >> k) > 0 ; k++) {
            if (1 & (i >> k)) {
                pos.first += v[k+20].first;
                pos.second += v[k+20].second;
                count++;
            }
        }
        //cout << "here" << endl;
        for (int j = 20-count ; j <= 20 ; j++) {
            ans[j] += maps[j][{e.first-pos.first, e.second-pos.second}];
        }
    }
    for (int i = 0 ; i < min(0, n-20) ; i++) {
        cout << ans[i] << endl;
    }
}