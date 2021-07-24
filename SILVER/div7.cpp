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


using namespace std;


int n;
int arr[1000000];
int pref[1000000];

int first[7] = {INT_MAX};
int last[7] = {-1};


int main() {
    cin >> n;
    int sum = 0;
    
    for (int i = 0; i < 7; i++) {
        first[i] = INT_MAX;
        last[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] %= 7;
        sum += arr[i];
        sum %= 7;

        //cout << sum << " ";
        first[sum] = min(first[sum], i);
        last[sum] = max(last[sum], i);
    }
    //cout << endl;
    int ans = 0;

    for (int i = 0 ; i < 7; i ++) {
        if (last[i] < n && first[i] < n && last[i] - first[i] > ans) {
            ans = last[i]-first[i];
        }
    }
    cout << ans << endl;


}