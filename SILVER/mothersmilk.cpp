/*
ID: vincent97
TASK: milk3
LANG: C++                 
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int ma,mb,mc;
bool v[60][60][60];

void dfs(int a, int b, int c) {
    //cout << a << " " << b << " " << c << endl;
    if (v[a][b][c]) {
        return;
    }
    v[a][b][c] = true;

    //pour from a
    int left = a+b - min(mb,a+b);
    dfs(left, min(mb,b+a), c);
    
    left = a+c - min(mc, a+c);
    dfs(left, b, min(mc, a+c));

    //pour from b
    left = a+b - min(ma,b+a);
    dfs(min(ma,a+b), left, c);

    left = b+c - min(mc, b+c);
    dfs(a, left, min(mc, b+c));

    //pour from c
    left = c+b - min(mb,c+b);
    dfs(a, min(mb,c+b), left);

    left = c+a - min(ma,c+a);
    dfs(min(ma, a+c), b, left);
}

int main() {
    #ifndef LOCAL
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    #endif
    cin >> ma >> mb >> mc;

    dfs(0, 0, mc);
    vector<int> sols;
    for (int i = 0 ; i < 60 ; i++) {
        for (int j = 0; j < 60 ; j++) {
            if (v[0][j][i]) { 
                sols.push_back(i);
                break;
            }
        }
    }
    for (int i = 0 ; i < sols.size() ; i++) {
        if (i == sols.size()-1) {
            cout << sols[i];
        } else {
            cout << sols[i] << " ";
        }
    }
    cout << endl;
}