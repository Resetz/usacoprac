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
using namespace std;

int n;
int maxi = 0;
int main() {
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num > maxi) maxi = num;
        sum += num;
    }
    cout << ((double) sum * 100) / (100 * n);
}