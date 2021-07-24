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
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int iin;
        cin >> iin;
        arr.push_back(iin);
    }
    sort(all(arr));
    if (n == 1 || n == 2) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    } else {
        
        int min2 = INT_MAX;
        int index = 0;
        for (int i = 0 ; i < n-1; i++) {
            if (min2 > arr[i+1] - arr[i]) {
                min2 = min(min2, arr[i+1]-arr[i]);
                index = i;
            }
        }
        cout << arr[index] << " ";
        for (int i = index+2; i < n; i++) {
            cout << arr[i] << " ";
        }
        for (int i = 0; i < index; i++) {
            cout << arr[i] << " ";
        }
        
        cout << arr[index+1] << " ";
    }
    cout << endl;
}
int main() {
    cin >> n;
    while(n--) solve();
}