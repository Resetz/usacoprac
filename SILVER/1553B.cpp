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

void solve() {
    string base;
    string goal;
    cin >> base >> goal;

    char begin = goal[0];

    for ( int i = 0 ; i < base.length() ; i++ ) {
        for ( int j = i ; j < base.length() ; j++ ) {
            if (j >= i && i - goal.length() >= 0) {
                bool found = true;
                for ( int k = 0 ; k < goal.length() ; k++ ) {
                    char c;
                    
                    if ((i + k) > j) {
                        c = base[j - (k - (j - i))];
                    } else {
                        c = base[i + k];
                    }
                    //cout << goal[k] << " " << c << endl;
                    if (goal[k] != c) {
                        found = false;
                        break;
                    }
                }
                if (found) {cout << "YES" << endl; return;}
            }
            //cout << endl;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}