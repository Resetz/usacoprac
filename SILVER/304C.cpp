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

int main(){
    int n;
    cin >> n;

    if (n % 2 == 0) {
        //impossible because the sum of both arrays mod n will never be the same of the sum of the other elements in the array mod n
        cout << -1 << endl;
    } else {
        for (int i = 0 ; i < n; i++) {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0 ; i < n; i++) {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0 ; i < n; i++) {
            cout << (i+i)%n << " ";
        }
        cout << endl;
    }
}