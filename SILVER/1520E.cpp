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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> sheep;
    for (int i = 0 ; i < n ; i++) {
        if (s[i] == '*') {
            sheep.push_back(i);
        }
    }
    long long moves = 0;
    if (sheep.size() != 0) {
        int pos = sheep[sheep.size()/2];
        int novertwo = sheep.size()/2;

        
        for (int i = 0 ; i < sheep.size(); i++) {
            //each sheep will move to pos - novertwo + i where pos is the position of the median sheep.
            moves += abs(sheep[i] - (pos - novertwo + i));
        }
    }
    cout << moves << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}