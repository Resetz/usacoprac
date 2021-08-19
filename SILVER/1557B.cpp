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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<long long,int>> sorted;
    for (int i = 0 ; i < n ; i++) {
        int num;
        cin >> num;
        sorted.push_back(make_pair(num, i));
    }
    if (n == 1) {
        cout << "YES" << endl; return;
    }
    sort(all(sorted));
    
    int m = 1;
    int prev = sorted[0].second;
    for (int i = 0 ; i < n ; i++) {
        if (i != 0) {
            if (prev + 1 != sorted[i].second) {
                m++;
            }
        }
        prev = sorted[i].second;
    }
    cout << ((m <= k) ? "YES" : "NO") << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}