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
        int sum = 0;
        cin >> num;
        for (int i = 0; i < num; i++) {
            int add;
            cin >> add;
            sum += add;
        }
        if (sum < num) {
            cout << num - sum;
        } else {
            cout << sum - num;
        }
    }
}