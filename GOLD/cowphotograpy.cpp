#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(5, vector<int>(n));
    vector<int> inv(n);
    vector<vector<int>> pl(5, vector<int>(n));
    vector<int> d;
    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> v[i][j];
            v[i][j]--;
            d.push_back(v[i][j]);
        }
    }
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (int i = 0 ; i < 5; ++i) {
        for (int j = 0 ; j < n ; j++) {
            int pre = v[i][j];
            v[i][j] = lower_bound(d.begin(), d.end(), v[i][j]) - d.begin();
            inv[v[i][j]] = pre;
        }
    }
    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < n ; j++) {
            pl[i][v[i][j]] = j;
        }
    }
    //cerr << "jere" << endl;
    //original value of a[i] can be obtained through d[a[i]]

    //cout << "here" << endl;

    vector<int> ans;
    for (int i = 0 ; i < n ; i++) {
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end(), [&pl](int a, int b) /* auto type resolve */ { 
        int k = 0;
        for (int i = 0; i < 5; i++) {
            k += (pl[i][a] > pl[i][b]) * 2 - 1;
        }
        return k < 0;
    });
    for (int i = 0 ; i < n ; i++) {
        cout << inv[ans[i]]+1 << endl;
    }
}