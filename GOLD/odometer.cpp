#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int dp2[2][18][10][10][18][18];

long long ans(long long l) {

    int l10 = 0;
    long long counting = 1;
    while (counting < l) {
        counting *= 10;
        l10++;
    }
    l10 -= 1;
    counting /= 10;

    vector<vector<vector<long long>>> dp(l10, vector<vector<long long>>(10, vector<long long>(19, 0)));
    for (int i = 0 ; i < 10 ; i++) {
        for (int j = 1 ; j < 10 ; j++) {
            dp[0][i][i == j] += 1;
        }
    }
    for (int i = 0 ; i < l10-1 ; i++) {
        for (int j = 0 ; j < 10 ; j++) {
            for (int k = 0 ; k < 18 ; k++) {
                if (dp[i][j][k]) {
                    dp[i+1][j][k+1] += dp[i][j][k];
                    dp[i+1][j][k] += 9*dp[i][j][k];
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0 ; i <= l10-1 ; i++) {
        for (int j = 0 ; j < 10 ; j++) {
            for (int k = (i+1)/2 ; k < 19 ; k++) {
                ans += dp[i][j][k];
            }
        }
    }
    //cout << "< " << counting << " = " << ans << endl;

    //cout << l << " " << l10 << " " << counting << " " << l/counting << endl;
    vector<vector<vector<long long>>> dp2[2];
    dp2[0].resize(l10+1, vector<vector<long long>>(10, vector<long long>(19, 0)));
    dp2[1].resize(l10+1, vector<vector<long long>>(10, vector<long long>(19, 0)));
    for (int i = 0 ; i < 10 ; i++) {
        dp2[1][0][i][(i==(l/counting))] = 1;
    }
    for (int i = 0; i < 10 ; i++) {
        for (int j = 1 ; j < (l/counting) ; j++) {
            dp2[0][0][i][i==j] += 1;
        }
    }

    //cout << "set dp states" << endl;

    counting /= 10;
    for (int i = 0 ; i < l10 ; i++) {
        //cout << counting << " " << (l/counting) % 10 << endl;
        for (int j = 0 ; j < 10 ; j++) {
            for (int k = 0 ; k < 18 ; k++) {
                if (dp2[0][i][j][k]) {
                    //cout << 0 << " | " << i << " " << j << " " << k << " = " << dp2[0][i][j][k] << endl;
                    //not the same
                    //no limit on transitions

                    //add number matching j
                    dp2[0][i+1][j][k+1] += dp2[0][i][j][k];
                    //add number not matching j - 9 digits you can add
                    dp2[0][i+1][j][k] += 9*dp2[0][i][j][k];
                } 
                if (dp2[1][i][j][k]) {
                    //cout << 1 << " | " << i << " " << j << " " << k << " = " << dp2[1][i][j][k] << endl;
                    //add number less than next digit
                    for (int o = 0 ; o < (l/counting)%10 ; o++) {
                        if ((i+1) == 3 && j == 4 && (k+(j==o)) == 2) {
                            cout << 1 << "! | " << i << " " << j << " " << k << " = " << dp2[1][i][j][k] << endl;
                        }
                        //cout << "+ " <<  i+1 << " " << j << " " << k+(j==o) << endl;
                        dp2[0][i+1][j][k+(j==o)] += dp2[1][i][j][k];
                    }

                    dp2[1][i+1][j][k+(j==((l/counting)%10))] += dp2[1][i][j][k];
                }
            }
        }
        counting /= 10;
    }
    //cout << "dp finished" << endl;
    for (int j = 0 ; j < 10 ; j++) {
        for (int k = (l10+2)/2 ; k < 19 ; k++) {
            if (dp2[1][l10][j][k]) {
                cout << 1 << " | " << l10 << " " << j << " " << k << " = " << dp2[1][l10][j][k] << endl;
            }
            if (dp2[0][l10][j][k]) {
                cout << 0 << " | " << l10 << " " << j << " " << k << " = " << dp2[0][l10][j][k] << endl;
            }
            ans += dp2[1][l10][j][k];
            ans += dp2[0][l10][j][k];
        }
    }
    
    cout << l << " " << ans << endl;
    return ans;
}   


long long countDoubles(long long l) {
    cout << l << endl;
    int l10 = 0;
    long long counting = 1;
    while (counting < l) {
        counting *= 10;
        l10++;
    }
    cout << l10 << endl;

    vector<vector<vector<long long>>> dp(l10, vector<vector<long long>>(l10+1, vector<long long>(l10+1, 0)));
    dp[0][1][0] = 1;
    dp[0][0][1] = 1;
    for (int i = 0 ; i < l10 ; i++) {
        for (int j = 0 ; j < l10 ; j++) {
            for (int k = 0 ; k < l10 ; k++) {
                cout << i << " " << j << " " << k << endl;
                if (dp[i][j][k]) {
                    dp[i+1][j+1][k] += dp[i][j][k];
                    dp[i+1][j][k+1] += dp[i][j][k];
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0 ; i < l10 ; i++) {
        for (int j = 0 ; j <= l10 ; j++) {
            cout << i << " " << j << " " << j << " " << dp[i][j][j] << endl;
            ans += dp[i][j][j] * 9*9;
        }
    }
    

    cout << "here " << ans << endl;
    memset(dp2, 0, sizeof(int)*2*18*10*10*18*18);
    counting /= 10;
    for (int i = 0 ; i < l10 ; i++) {
        for (int num1 = 1; num1 < 10 ; num1++) 
        for (int num2 = num1+1; num2 < 10 ; num2++) {
            for (int j = 0 ; j < 18 ; j++) {
                for (int k = 0; k < 18 ; k++) {
                    if (dp2[0][i][num1][num2][j][k]) {
                        dp2[0][i+1][num1][num2][j+1][k] += dp2[0][i][num1][num2][j][k];
                        dp2[0][i+1][num1][num2][j][k+1] += dp2[0][i][num1][num2][j][k];
                    }
                    if (dp2[1][i][num1][num2][j][k]) {
                        bool f = num1 == (l/counting) % 10;
                        dp2[1][i+1][num1][num2][j+f][k+!f] = 1;
                        dp2[0][i+1][num1][num2][j+!f][k+f] += 1;
                    }
                }
            }
        }
        counting /= 10;
    }
    for (int num1 = 1; num1 < 10 ; num1++) 
    for (int num2 = num1+1; num2 < 10 ; num2++) {
        for (int j = 0 ; j < 18 ; j++) {
            ans += dp2[0][l10][num1][num2][j][j];
            ans += dp2[1][l10][num1][num2][j][j];
        }
    }
    return ans;
}

int main() {
    long long f,t;
    cin >> f >> t;
    cout << (ans(t)-countDoubles(t)) - (ans(f-1)-countDoubles(f-1)) << endl;
    cout << "w" << endl;
    cout << countDoubles(100);
}