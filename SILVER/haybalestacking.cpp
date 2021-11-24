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

vector<int> haybales;

int n, m;
bool solve(long long k) {
    // simulate
    int stacks = 1;
    long long height = haybales[0];
    long long last = haybales[0];
    for (int i = 1 ; i < n ; i++) {
        
        if (haybales[i] > last || height + haybales[i] > k) {
            stacks++;
            height = haybales[i];
        } else {
            height += haybales[i];
        }
        last = haybales[i];
        if (haybales[i] > k) {
            return false;
        }
    }
    if (stacks <= m) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> n >> m;

    haybales.resize(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> haybales[i];
    }

    // simulate first;
    int stack_size = 0;
    int stacks = 0;
    int height = 0;
    int last = haybales[0];
    int max_stack = 0;
    for (int i = 1 ; i < n ; i++) {
        if (last < haybales[i]) {
            max_stack = max(stack_size, max_stack);
            stacks++;
            height = 0;
            stack_size = 0;
        } else {
            height += haybales[i];
            stack_size++;
        }
        last = haybales[i];
    }
    if (stacks > m) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }


    long long high = 9223372036854775807;
    long long low = 0;
    long long ans;

    while (high >= low) {
        long long mid = (high + low) / 2;

        bool res = solve(mid);
        if (res) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << ans << endl;
}