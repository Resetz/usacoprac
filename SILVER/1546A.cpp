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
#include <unordered_set>

#define all(n) n.begin(), n.end()
using namespace std;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> arr1(100,0);
    vector<int> arr2(100,0);
    vector<int> diff(100,0);
    int total = 0;
    int posSum = 0;
    for (int i = 0 ; i < n ; i++) {
        cin >> arr1[i];
    }
    for (int i = 0 ; i < n; i++) {
        cin >> arr2[i];
        sum += arr1[i] - arr2[i];
        posSum += max(0, arr1[i]-arr2[i]);
        diff[i] = arr1[i]-arr2[i];
    }

    if (sum != 0) {
        cout << "-1" << endl;
        return;
    }
    if (posSum == 0) {
        cout << 0 << endl;
        return;
    }
    cout << posSum << endl;
    for (int i = 0; i < n; i++) {
        if (diff[i] > 0) {
            for (int j = 0; j < n; j++) {
                if (diff[i] <= 0) {
                    break;
                }
                int a = min(-diff[j], diff[i]);
                if (diff[j] < 0) {
                    for (int k = 0 ; k < a; k++) {
                        cout << i+1 << " " << j+1 << endl;
                        diff[j]++;
                        diff[i]--;
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}