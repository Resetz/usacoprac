// nerdysahil
#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define M 1e9+7
#define ll long long
#define all(a) a.begin(),a.end()
#define nline "\n"
#define setbits(n) __builtin_popcount(n)
 
ll fast_expo(ll a, ll n) {ll ans = 1; while (n > 0) {if (n & 1) {ans *= a;} a *= a; n >>= 1;} return ans;}
 
//-------------------------------------------------------------------//
//                                 _                        __       //
//   ___  ___ _  _____ ____  ___ _(_)  _____   __ _____    / /       //
//  / _ \/ -_) |/ / -_) __/ / _ `/ / |/ / -_) / // / _ \  /_/        //
// /_//_/\__/|___/\__/_/    \_, /_/|___/\__/  \_,_/ .__/ (_)         //
//                         /___/                 /_/                 //
//-------------------------------------------------------------------//

char grid[200000][100000];
int n,m;
 void solve() {
    int len, n;
    cin >> n >> len;

    for (int i = 0 ; i < n*2-1 ; i++ ){
        for (int j = 0 ; j < len; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < len; i++){
        int count[26] = {0};
        for (int j = 0 ; j < n*2-1; j++) {
            count[grid[j][i]-'a']++;
        }
        for (int j = 0; j < 26; j++) {
            if (count[j] % 2 == 1) {
                cout << (char) (j+'a');
                break;
            }
        }
    }
    cout << endl;
    cout.flush();
}

int main() {
    fastio;
    int n;
    cin >> n;

    while (n--) solve();
}