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


set<int> t;
int main() {
    string s;
    cin >> s;
    int i = 0;
    for (int j = 0; j < s.length(); j++) {
        if (t.count(s[j]) >= 1) {
            continue;
        } else {
            t.insert(s[j]);
            i++;
        }
    }
    if (i % 2 == 1) {
        cout << "IGNORE HIM!";
    } else {
        cout << "CHAT WITH HER!";
    }
}