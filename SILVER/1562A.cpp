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

void solve() {
    int i, j;
    cin >> i >> j;

    int k = (j+1)/2;
    if (i > k) {
        cout << j % i << endl;
    } else {
        if (j % k == 0) j--;
        cout << j % ((i > k) ? i : k) << endl;
    }
}
int main() {
    int n;
    cin >> n;
    while (n--) solve();
}