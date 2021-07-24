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
    
    int n,r,l;
    cin >> n >> r >> l;

    vector<int> arr(n,0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(all(arr));
    /*
    int j = 0;
    int ans = 0;
    for (int i = n-1; i >= 0 && j < i; i--) {
        if (arr[j] + arr[i] >= r && arr[j] + arr[i] <= l) {
            ans += (i-j);
            j++;
            i++;
        }
        
    }
    cout << ans << endl;*/
}
int main() {
    int n;
    cin >> n;
    while(n--) solve();
}