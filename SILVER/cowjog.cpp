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
#include <unordered_map>
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
pair<int,int> nums[100000];
int main() {
    cin >> n;
    
    int min = 10e9;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        nums[i] = make_pair(a,b);
        if (b < min) {
            min = b;
        }
    }
    int ans = 0;
    int minSoFar = 10e9;

    for (int i = n-1; i >= 0; i--) {
        if (nums[i].second <= minSoFar) {
            minSoFar = nums[i].second;
            ans++;
        } 
    }
    cout << ans;
}