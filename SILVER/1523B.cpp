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

int other = 0;
int main() {
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> other;
        }
        cout << m*3 << endl;
        for (int i = 1; i <= m; i += 2) {
            cout << 1 << " " << i << " " << i+1 << endl;
            cout << 2 << " " << i << " " << i+1 << endl;
            cout << 1 << " " << i << " " << i+1 << endl;
            cout << 2 << " " << i << " " << i+1 << endl;
            cout << 1 << " " << i << " " << i+1 << endl;
            cout << 2 << " " << i << " " << i+1 << endl;
        }
    }
}