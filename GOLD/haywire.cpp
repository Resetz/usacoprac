#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0 ; i < n ;i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    int k = 2 << n;

    vector<int> dp(k, INT_MAX);
    dp[0] = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0, int l = i ; l > 0 ; j++, l >> 1) {
            if (l & 1) {
                for (int j = 0 ; j < n ; j++) {
                    if 
                }
            }
        }
    }
}