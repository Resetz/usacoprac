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

int n;
int m;
vector<int> arr;


struct less_than_key
{
    inline bool operator() (const int& struct1, const int& struct2)
    {
        return (struct1 % 2 < struct2 % 2);
    }
};

void solve() {
    cin >> n; 

    arr.clear();

    for (int i = 0 ; i < n ; i ++) {
        cin >> m;
        arr.push_back(m);
    }

    sort(arr.begin(), arr.end(), less_than_key());

    int ans = 0;
    for (int i = 0 ; i < n; i ++ ) {
        for (int j = i+1 ; j < n; j++) {
            if (__gcd(arr[i], arr[j]*2) > 1) {
                //cout << arr[i] << ", " << arr[j] * 2 << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int i;
    cin >> i;
    while (i--) solve();
}