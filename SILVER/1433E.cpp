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
using namespace std;

#define all(n) n.begin(), n.end()
using namespace std;

int main() {
    int n;
    cin >> n;
    n = n/2-1;
    unsigned long long ans = 1;
    unsigned long long arr[20];
    arr[0] = 1;
    for (int i = 1 ; i < 20 ; i++) {
        arr[i] = arr[i-1] * i;
    }
    cout << arr[n*2+1]/(n+1) << endl;
}