#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> dp;

int r,c;

void solve(int i, int j) {

    for (int cr = i+1 ; cr < r; cr++) {
        for (int cc = j+1 ; cc < c ; cc++) {
            if (v[cr][cc] != v[i][j]) { 
                dp[cr][cc] = (dp[cr][cc] + dp[i][j]) % 1000000007;

            }
        }
    }
}

int main() {
    cin >> r >> c;
    v.resize(r,vector<int>(c));
    dp.resize(r,vector<int>(c));

    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < c; j++) cin >> v[i][j];
    }
    dp[0][0] = 1;

    for (int i = 0 ; i < r ; i++) {
        for (int j = 0; j < c ; j++) {
            if (dp[i][j] == 0) continue;
            solve(i,j);
        }
    }
    cout << dp[r-1][c-1] << endl;
}