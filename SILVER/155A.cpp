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
int k;

int main() {
    cin >> n;
    int mini = INT_MAX;
    int maxi = -INT_MAX;
    int ans =0 ;
    for (int i = 0 ; i < n ; i++) {
        int num;
        cin >> num;
        if (num < mini || num > maxi) {
            ans ++;
        } 
        mini = min(num, mini);
        maxi = max(num, maxi);
    }
    cout << ans-1;
}