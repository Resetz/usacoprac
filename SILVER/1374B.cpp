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
    int num;
    cin >> num;

    int div2 = 0;
    while (num%2 == 0) {
        num /= 2;
        div2++;
    }
    int div3 = 0;
    while (num%3 == 0) {
        div3++;
        num /= 3;
    }
    if (div2 > div3) {
        cout << -1;
    } else if (num == 1 && div2 <= div3) {
        cout << 2*div3-div2;
    } else {
        cout << -1;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}