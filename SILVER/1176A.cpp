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
    long long n;
    cin >> n;

    int total = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else if (n % 3 == 0) {
            n = n * 2 / 3;
        } else if (n % 5 == 0) {
            n = n * 4 / 5;
        } else {
            cout << -1 << endl;
            return;
        }
        total++;
    }
    cout << total << endl;
}
int main() {
    int m;
    cin >> m;

    while (m--) solve();
}