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

int a[50];
int b[50];

void solve() {
    int n;
    cin >> n;
    bool prev;
    char c;
    cin >> c;
    prev = c == 'a';
    bool done = false;
    for (int i = 0; i < n-1; i++) {
        cin >> c;
        if ((prev != (c == 'a')) && !done) {
            cout << i + 1 << " " << i + 2 << endl;
            done = true;
        }
        prev = c == 'a';
    }
    if (!done) cout << "-1 -1" << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}