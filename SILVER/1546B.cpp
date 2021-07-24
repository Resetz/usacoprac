#include <iostream>
#include <string>
#include <cstdio>
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
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_set>


#define all(n) n.begin(), n.end()
using namespace std;

const int Maxn=1000000;
int grid[1000000][26];
int n,m;
void solve() {
    int len, n;
    cin >> n >> len;

    for (int i = 0 ; i < len ; i++) {
        for (int j = 0 ; j < 26; j++) {
            grid[i][j] = 0;
        }
    }

    for (int i = 0 ; i < n*2-1 ; i++ ) {
        for (int j = 0 ; j < len; j++) {
            char c;
            cin >> c;
            grid[j][c-'a']++;
        }
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 26; j++) {
            if (grid[i][j] % 2 == 1) {
                cout << (char) (j+'a');
            }
        }
    }
    
    
    cout << endl;
    cout.flush();
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}