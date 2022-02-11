#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n, m;
    n = s1.size();
    m = s2.size();

    vector<int> dp(m+1); // row 0
    vector<int> ne/*xt*/(m+1); // row 1

    for (int i = 0 ; i < m+1; i++) dp[i] = i;

    for (int i = 1; i <= n ; i++) {
        ne[0]++;
        for (int j = 1; j <= m ; j++) {
            if (s1[i-1] == s2[j-1]) {
                ne[j] = dp[j-1];
            }
            else {
                ne[j] = 1 + min(dp[j-1], min(dp[j], ne[j-1]));
            }
        }
        dp = ne;
    }
    cout << ne[m] << endl;
}