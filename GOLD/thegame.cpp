#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int n;

vector<vector<int>> dp;

int go(int l, int r) {
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    return dp[l][r] = max(v[l] - go(l+1,r), v[r] - go(l,r-1));
}

int main() {
    cout << "here" << endl;
    cin >> n;
    v.resize(n);
    dp.resize(n, vector<int>(n, -1));
    int sum = 0;
    for (int i = 0; i < n ; i++) {
        cin >> v[i];
        dp[i][i] = v[i];
        sum += v[i];
    }

    cout << (go(0, n-1)+sum)/2 << " " << sum - ((go(0, n-1)+sum)/2) << endl;
}