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
#include <climits>
using namespace std;

int n;

void solve() {
    int len;
    cin >> len;
    int odd = 0;
    int even = 0;

    int arr[50];
    for (int i = 0 ; i < len ; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    if (odd % 2 == 0 && even % 2 == 0) {
        cout << "YES" << endl;
        return;
    }
    else if (odd % 2 == 1 && even % 2 == 1){
        for (int i = 0 ; i < len ; i++) {
            for (int j = 0 ; j < len ; j++) {
                if (i == j) {
                    continue;
                } else {
                    if (abs(arr[i]-arr[j]) == 1) {
                        cout << "YES" << endl;
                        return;
                    }
                }
            }
        }
        cout << "NO" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    cin >> n;
    while (n--) solve();
}