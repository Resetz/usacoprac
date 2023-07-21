#include <iostream>
#include <vector>
#include <map>
using namespace std;

int tonum(char c) { 
    if (c >= 'a' && c <= 'z') {return c-'a';}
    else {return c-'A'+26;}
}

int main() {
    int u,l,p;
    cin >> u >> l >> p;

    map<int,vector<int>> m;
    for (int i = 0 ; i < 52 ; i++) {
        m[i] = vector<int>();
    }
    for (int i = 0 ; i < p ; i++) {
        char a,b; cin >> a >> b;
        //cout << a << " " << b << endl;
        a = tonum(a);
        b = tonum(b);
        m[a].push_back(b);
    }
    //cout << " asdf " << endl;

    vector<vector<vector<long long>>> v(u+3, vector<vector<long long>>(l+3, vector<long long>(52)));
    for (int i = 0 ; i < 52 ; i++) {
        for (int j = 0 ; j < m[i].size() ; j++) {
            v[(m[i][j] >= 26)+(i >= 26)][!(m[i][j] >= 26)+!(i >= 26)][m[i][j]] += 1;
           // cout << (!(m[i][j] >= 26)+!(i >= 26)) << " " << ((m[i][j] >= 26)+(i >= 26)) << " " << m[i][j] << endl;
        }
    }
    

    for (int i = 0 ; i <= u ; i++) {
        for (int j = 0 ; j <= l ; j++) {
            for (int k = 0 ; k < 52 ; k++) {
                if (v[i][j][k] == 0) continue;
                for (int n = 0 ; n < m[k].size() ; n++) {
                    bool s = m[k][n] >= 26;
                    v[i+s][j+!s][m[k][n]] += v[i][j][k];
                    v[i+s][j+!s][m[k][n]] %= 97654321;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0 ; i < 52; i++) {
        ans = (ans + v[u][l][i]) % 97654321;
    }
    cout << ans << endl;
}