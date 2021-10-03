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

char solve(int n) {
    if (n < 3) {
        if (n == 0) {
            return 'm';
        } else {
            return 'o';
        }
    }
    
    int prev= 0;
    int len = 3;
    int inc = 4;
    while (n > len){
        prev = len;
        len = len * 2 + inc;
        inc++;
    }
    inc--;
    // 0 1 2 3 4 5 6 7 8 9
    // m o o m o o o m o o

    if (n >= prev && n < prev + inc) {
        if (n == prev) {
            return 'm';
        } else {
            return 'o';
        }
    } else {
        return solve(n-prev-inc);
    }

}

int main() {
    int n;
    cin >> n;
    cout << solve(n-1);
}