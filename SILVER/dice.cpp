#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

int n,S,e;


vector<int> cnt;
vector<vector<int>> pairs;
string s;

int a = 0; 

void solve(int c) {

    if (c > n) {
        
        for (int i = 0 ; i < e ; i++) {
            bool good = true;
            for (int j = 0 ; j < S ; j++) {
                if (pairs[i][j] > cnt[j]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                a++;
                return;
            }
        }
        return;
    }
    for (int p = 0 ; p < S ; p++) {
        cnt[p]++;

        solve(c+1);

        cnt[p]--;
    }
}

int main() {
    cin >> n >> S >> e;
    for (int i = 0 ; i < e ; i++) {
        pairs.push_back(vector<int>());
        pairs[i].resize(S);
    } 
    for (int i = 0 ; i < e ; i++) {
        cin >> s;
        stringstream ss(s);
        char c;
        int u = count(s.begin(),s.end(),'x');
        for (int j = 0 ; j < u; j++) {
            int a, b;
            if (j == u-1) {
                ss >> a >> c >> b;
            } else {
                ss >> a >> c >> b >> c;
            }

            //cout << a << " " << b << endl;
            b--;
            pairs[i][b] = a;
        }
    } 
    cnt.resize(S);
    solve(1);
    cout << a << endl;
    return 0;
}