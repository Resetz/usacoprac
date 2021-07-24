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

#define all(n) n.begin(), n.end()
using namespace std;

int a[100001];
int b[100001];
int c[100001];
int main() { 
    int n,k;

    int aCount = 0;
    int bCount = 0;
    int cCount = 0;
    cin >> n >> k;

    for (int i = 1 ; i <= n; i++) {
        int m;
        cin >> m;
        if (m == 1) {
            aCount++;
        } else if (m == 2) {
            bCount++;
        } else {
            cCount++;
        }
        a[i] = aCount;
        b[i] = bCount;
        c[i] = cCount;
    }

    for (int i = 0; i < k; i++) {
        int from,to;
        cin >> from >> to;
        cout << a[to] - a[from-1] << " " << b[to] - b[from-1] << " " << c[to] - c[from-1] << endl;
    }

}
