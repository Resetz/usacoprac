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
#include <unordered_map>

#define all(n) n.begin(), n.end()
using namespace std;


void solve() {
    int n;
    cin >> n;
    unordered_map<int, unsigned long long> mmap;
    mmap.reserve(7000);

    int m = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        m = max(num, m);
        mmap[num]++;
    }
    
    unsigned long long ans = 1;
    for (int i = 1 ; i <= n ; i++) {
        ans = ans * i % 998244353;
    }
    unsigned long long temp = ans;
    if (mmap[m] != 1) {
        ans = 0;
    }
    else if (mmap.find(m-1) == mmap.end()) {
        ans = temp;
    } else {
        ans /= (mmap[m-1]+1);
    }
    cout << temp - ans << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}