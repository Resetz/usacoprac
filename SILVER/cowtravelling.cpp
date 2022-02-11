#include <iostream>
#include <vector>
#include <map>

using namespace std;

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0 ,0};

vector<vector<vector<int>>> dp;
vector<vector<int>> v;
int main() {
    int r,c,t;
    cin >> r >> c >> t;
    int sr, sc, er, ec;


    v.resize(    r,vector<int>(c));
    dp.resize(t+1, vector<vector<int>>(r,vector<int>(c)));

    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < c ; j++) {
            char cj;
            cin >> cj;
            if (cj == '*') {
                v[i][j] = 0;
            } else {
                v[i][j] = 1;
            }
        }
    }
    
    cin >> sr >> sc >> er >> ec;
    sr--;
    sc--;
    er--;
    ec--;

    dp[0][sr][sc] = 1;
    for (int time = 0 ; time < t ; time++) {
        for (int i = 0 ; i < r ; i++) {
            for (int j = 0 ; j < c; j++) {
                if (dp[time][i][j] != 0) {
                    for (int k = 0 ; k < 4 ; k++) {
                        if (i+di[k] >= 0 && i+di[k] < r && j+dj[k] >= 0 && j+dj[k] < c && v[i+di[k]][j+dj[k]] == 1) {
                            dp[time+1][i+di[k]][j+dj[k]] += dp[time][i][j];
                        }
                    }
                }
            }
        }
    }
    cout << dp[t][er][ec] << endl;
}