#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>

#define all(n) n.begin(), n.end()
using namespace std;

int A, B, C;
bool sol[21][21][21];
bool v[21][21][21];
void dfs(int a, int b, int c) {
    int _a = a, _b = b, _c = c;
    if (v[a][b][c]) {
        return;
    }
    v[a][b][c] = true;
    //cout << a << " " << b << " " << c << endl;
    if (a > 0 && b < B) {
        int d = min(a, B - b);
        a -= d;
        b += d;
        dfs(a,b,c);
        a = _a;
        b = _b;
    }
    if (a > 0 && c < C) {
        int d = min(a, C - c);
        a -= d;
        c += d;
        dfs(a,b,c);
        a = _a;
        c = _c;
    }
    if (b > 0 && c < C) {
        int d = min(b, C - c);
        b -= d;
        c += d;
        dfs(a,b,c);
        b = _b;
        c = _c;
    }
    if (b > 0 && a < A) {
        int d = min(b, A - a);
        b -= d;
        a += d;
        dfs(a,b,c);
        b = _b;
        a = _a;
    }    
    if (c > 0 && a < A) {
        int d = min(c, A - a);
        c -= d;
        a += d;
        dfs(a,b,c);
        c = _c;
        a = _a;
    }    
    if (c > 0 && b < B) {
        int d = min(c, B - b);
        c -= d;
        b += d;
        dfs(a,b,c);
        c = _c;
        b = _b;
    }    
}

int main() {
    //int a, b, c;
    cin >> A >> B >> C;
    for (int i = 0 ; i <= 21 ; i++) {
        for (int j = 0 ; j <= 21 ; j++) {
            for (int k = 0 ; k <= 21 ; k++) {
                v[i][j][k] = false;
            }
        }
    }
    dfs(0, 0, C);
    vector<int> ans;
    for (int i = 0 ; i <= C ; i++) {
        for (int j = 0 ; j <= B ; j++)  {
            if (v[0][j][i] && !count(ans.begin(), ans.end(), i)) {
                ans.push_back(i);
            }
        }
    }
    for (int i : ans) {
        cout << i << " ";
    }
}