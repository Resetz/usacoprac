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
    unsigned long long last = 1;
    int most = 0;
    vector<int> ret;
    for (int i = 1; i < n; i++) {
        if (__gcd(n,i) != 1 && i != 1) {
            continue;
        }
        last *= i;
        last %= n;
        ret.push_back(i);
        most++;
    }
    int skip = -1;
    if (last % n != 1) {
        skip = last % n;
        most--;
    }
    
    cout << most << endl;
    
    for (int i = 0; i < ret.size(); i++) {
        if (skip == ret[i]) {
            continue;
        }
        cout << ret[i] << " ";
    } 

}