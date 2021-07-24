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
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define all(n) n.begin(), n.end()
using namespace std;

void solve() {
    int n;
    cin >> n;
    int odd = 0, even = 0;
    //cout << "n = " << n << endl;
    for (int i = 0; i < n*2; i++) {
        int num;
        cin >> num;
        num % 2 == 0 ? even++ : odd++;
    }
    if (odd == even) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        solve();
    }
}