#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int r,c;
vector<vector<int>> arr;
vector<vector<int>> dp;

int solve(int a, int b) {
    if (a < 0 || a >= r || b < 0 || b >= c) return -INT_MAX;
    //cout << a << " " << b << " " << arr[a][b] << endl;
    if (b == c-1) return arr[a][b];
    if (dp[a][b] != -1) return dp[a][b];

    dp[a][b] = arr[a][b] + max(solve(a+1, b+1), max(solve(a, b+1), solve(a-1, b+1)));
    return dp[a][b];
}

int main() {
    cin >> r >> c;
    arr.resize(r, vector<int>(c));
    dp.resize(r, vector<int>(c, -1));
    for (int i = 0; i < r ; i++) {
        for (int j = 0 ; j < c ; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        if (i != 0) {
            arr[i][0] = -INT_MAX;
            //cout << i << " " << 0 << endl;
        }
        if (i != r-1) {
            arr[i][c-1] = -INT_MAX;
            ///cout << i << " " << c-1 << endl;
        }
    }


    cout << solve(0,0) << endl;
}