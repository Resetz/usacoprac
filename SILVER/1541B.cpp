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

int n;
void solve() {
    int n;
    cin >> n;
    vector<int> arr(2*n+1, -1);
    for (int i = 1; i <= n; i++ ) {
        int num;
        cin >> num;
        arr[num] = i;
    }
    cout << endl;
    //sum must be less than 2*n because the answer must be in the array
    int ans = 0;
    for (int i = 3; i <= 2 * n; i++ ) {
        for (int j = 1; j * j <= i; j++) {
            //cout << "i = "  << i  << " j = " << j << endl;
            if ((i % j) == 0 && (j * j) != i && arr[j] != -1 && arr[i/j] != -1 && (arr[j] + arr[i/j]) == i) {
                ans++;
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