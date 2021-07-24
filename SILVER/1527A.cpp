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

void solve() {
    unsigned int n;
    cin >> n;
    int i = 0;
    int last = 0;
    while ( i < 30) {
        if ((n & (1<<i)) >0) {
            last = i;
        }
        i++;
    }
    cout << (1<<last)-1<< endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}