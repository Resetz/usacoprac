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
#include <climits>
using namespace std;

int a;
int n;
int k;
int num;

int main() {
    cin >> num;
    while (num--) {
        cin >> n >> k >> a;
        string s = "";
        int i = 0;

        while (i < n) {
            s += 'a' + (i % a);
            i++;
        }
        cout << s << endl;
    }
}