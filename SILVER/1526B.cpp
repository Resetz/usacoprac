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

int main() {
    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        bool found = false;
        for (int i = 0; i < 11; i++) {

            if (num % 11 == 0) {
                cout << "YES" << endl;
                found = true;
                break;
            } 
            num-= 111;
            if (num < 0) {
                cout << "NO" << endl;
                found = true;
                break;
            }
            
        }
        if (!found) {
                cout << "NO" << endl;
            }
    } 
}