#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,I,h,r;
    cin >> n >> I >> h >> r;
    I--;

    vector<vector<bool>> dup(n,vector<bool>(n, 0));

    vector<pair<int,int>> intervals;
    for (int i = 0 ; i < r ; i++) {
        int f, t;
        cin >> f >> t;
        f--; t--;
        if (f > t) {
            int temp = f;
            f = t;
            t = temp;
        }
        if (!dup[f][t]) {
            intervals.push_back(pair<int,int>{f,t});
            dup[f][t] = true;
        }
    }


    //cout << "here" << endl;
    vector<int> inc(n,0);
    vector<int> dec(n,0);
    for (int i = 0 ; i < intervals.size() ; i++) {
        dec[intervals[i].first]--;
        inc[intervals[i].second]++;
    }


    vector<int> pf(n, 0);
    int cur = 0;

    for (int i = 0 ; i < n ; i++) {
        cur += inc[i];
        pf[i] = cur;
        cur += dec[i];
        //cout << "- " << pf[i] << endl;
    }

    int delta = h - pf[I];
    for (int i = 0 ; i < n ; i++) {
        cout << pf[i]+delta << endl;
    }
}