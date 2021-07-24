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
set<int> t;
int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    t.insert(a);
    if (t.count(b)) {
        ans++;
    } 
    t.insert(b);
    if (t.count(c)) {
        ans++;
    } 
    t.insert(c);
    if (t.count(d)) {
        ans++;
    } 
    t.insert(d);
    cout << ans;

}