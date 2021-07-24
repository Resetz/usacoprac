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
#include <unordered_map>
#include <stdlib.h>
#include <assert.h>
using namespace std;


pair<int,int> make(int i, int j) {
    int gcd = __gcd(i,j);
    i /= gcd;
    j /= gcd;
    return {i,j};
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pair<int,int>, int> m;
    int d = 0;
    int k = 0;
    pair<int,int> current = make_pair(0,0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') {
            current.first ++;
        } else {
            current.second ++;
        }
        cout << ++m[make(current.first,current.second)] << " ";
    }
    cout << endl;
}

int n;
int main() {
    cin >> n;
    while (n--) {
        solve();
    }
}