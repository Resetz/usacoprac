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
    int n;
    cin >> n;
    while (n--) {
        int check;
        cin >> check;
        if (check%2 == 1) {
            cout << "Bob" << endl;
            continue;
        } 
        int log2 =0;
        int checking = check;
        bool powof2 = true;
        while (checking > 1) {
            if (checking % 2 != 0) {
                powof2 = false;
                break;
            }
            checking /= 2;
            log2++;
        }
        if (!powof2) {
            cout << "Alice" << endl;
        } else if (log2 % 2 == 0) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
}