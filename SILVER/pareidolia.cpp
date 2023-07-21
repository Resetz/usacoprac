#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    
    #define int long long

    string s;
    cin >> s;

    int n = s.size();
    int cur = 0;
    string B = "bessie";
    string b = "besi";
    vector<int> pos(6);
    vector<vector<int>> next(4);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < b.size() ; j++) {
            if (b[j] == s[i]) {
                next[j].push_back(i);
            }
        }
    }
    vector<int> right(n, 0);
    vector<int> ptr(6, 0);
    //bessie
    vector<int> rel = {0,1,2,2,3,1};
    bool good = true;
    //cout << n << endl;
    for (int i = 0 ; i < n ; i++) {
        if ( i == 0 ) {
            //process
            for (int j = 1 ; j < 6 ; j++) {
                while (ptr[j] < next[rel[j]].size() && next[rel[j]][ptr[j]] <= next[rel[j-1]][ptr[j-1]]) {
                    ptr[j]++;
                }
                if (ptr[j] == next[rel[j]].size()) {
                    good = false;
                    break;
                }
            }
        }
        if (good) {
            right[i] = next[rel[5]][ptr[5]];
        } else {
            right[i] = -1;
        }

        if (s[i] == 'b') {
            ptr[0]++;
            //process
            if (ptr[0] == next[0].size()) good = false;
            for (int j = 1 ; j < 6 ; j++) {
                while (ptr[j] < next[rel[j]].size() && next[rel[j]][ptr[j]] <= next[rel[j-1]][ptr[j-1]]) {
                    ptr[j]++;
                }
                if (ptr[j] == next[rel[j]].size()) {
                    good = false;
                    break;
                }
            }
        }
    }

    vector<int> dp(n);
    int ans = 0;
    for (int i = n-1 ; i >= 0 ; i--) {
        if (right[i] == -1) {
            dp[i] = 0;
        } else {
            dp[i] = n - right[i] + dp[right[i]];
        }
        ans += dp[i];
    }
    cout << ans << endl;
}