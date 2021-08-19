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
using namespace std;

#define all(n) n.begin(), n.end()
using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {
            cout << (i == n/2 ? 'a' : 'b');
        }
    } else {
        for (int i = 0 ; i < n-1 ; i++) {
            cout << (i == n/2 ? 'a' : 'b');
        } 
        cout << 'c';
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}