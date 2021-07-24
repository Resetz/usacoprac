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

int main() {
    int i;
    cin >> i;
    if (i % 2 == 1 || i == 0) {
        cout << -1;
    } else {
        for (int j = 2; j <= i; j+=2) {
            cout << j << " " << j-1 << " ";
        }
    }
}