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
using namespace std;

#define all(n) n.begin(), n.end()
using namespace std;

bool check(vector<int> v) {
    for (int i = 1 ; i < v.size() ; i++) {
        if (v[i-1] > v[i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n, 0);

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    int ans = 0;
    while (!check(v)) {
        ans++;
        if (ans % 2 == 0) {
            for (int i = 1; i < n ; i += 2) {
                if (v[i] > v[i+1]) iter_swap(v.begin() + i, v.begin() + i + 1);
            }
        } else {
            for (int i = 0; i < n-1 ; i += 2) {
                if (v[i] > v[i+1]) iter_swap(v.begin() + i, v.begin() + i + 1);
            }
        }

    }
    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}