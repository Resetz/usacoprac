#include <iostream>
#include <string>
#include <cstdio>
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

int main() {
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i ++) {
        int num;
        cin >> num;
        cout << (num+1)/10 << endl;
    }
}