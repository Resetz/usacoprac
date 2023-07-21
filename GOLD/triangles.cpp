#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>

#define int long long

using namespace std;

long long cross(pair<int, int> a, pair<int, int> b) {
    return a.first*b.second - a.second*b.first;
 }


ostream& operator<<(ostream&o, pair<int, int> a) {
    return o << "{" << a.first << ", " << a.second << "}";
}

int32_t main() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0 ; i < n ;i++) {
        for (int j = i+1 ; j < n ; j++) {
            for (int k = 0 ; k < n ; k++) {
                assert(i < n && j < n && k < n);
                if (v[k].first >= v[i].first && v[k].first < v[j].first) {
                    pair<int,int> d1 = {v[j].first - v[i].first, v[j].second - v[i].second};
                    pair<int,int> d2 = {v[k].first - v[j].first, v[k].second - v[j].second};
                    if (cross(d2,d1) > 0) {
                        //cout << v[k] << " is under " << v[i] << " and " << v[j] << endl;
                        dp[i][j]++;
                    }
                }
            } 
        }
    }

    //cout << "here" << endl;
    vector<int> ans(n+1);
    for (int i = 0 ; i < n ; i++) {
        for (int j = i+1 ; j < n ; j++) {
            for (int k = j+1 ; k < n ; k++) {
                //cases
                pair<int,int> d1 = {v[j].first - v[i].first, v[j].second - v[i].second};
                pair<int,int> d2 = {v[k].first - v[j].first, v[k].second - v[j].second};
                int cur = 0;
                if (cross(d1,d2) < 0) {
                    if (v[i].first == v[j].first) {
                        cur = dp[j][k] - dp[i][k] - 1;
                    } else {
                        cur = dp[i][j] + dp[j][k] - dp[i][k];
                    }
                } else {
                    if (v[j].first == v[k].first) {
                        cur = dp[i][k] - dp[i][j];
                    } else {
                        cur = dp[i][k] - dp[i][j] - dp[j][k] - 1;
                    }
                }
                //cout << cur << endl;
                ans[cur]++;
            }
        }
    }
    for (int i = 0 ; i < n-2 ; i++) {
        cout << ans[i] << endl;
    }
}