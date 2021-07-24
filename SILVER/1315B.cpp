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
int main() {
    cin >> n;
    while (n--) {
        int x,y,i,j;
        cin >> x >> y >> i >> j;

        int x1 = max(x,y);
        int y1 = max(i,j);
        int x2 = min(x,y);
        int y2 = min(i,j);
        if (x1 == y1) {
            if (x2+y2 == y1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }else {
                cout << "NO" << endl;
            }
    }
}