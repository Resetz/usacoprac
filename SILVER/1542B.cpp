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
    long long a, b, n;
    cin >> n >> a >> b;
    long long num = 1;
    while (num <= n) {
        if ((n - num) % b == 0) {
            cout << "YES" << endl;
            return;
        } 
        num *= a;
        if (num == 1) {
            break;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}