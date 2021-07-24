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

int t;
int n;

void solve() {
    vector<int> lengths;
    string s;
    cin >> s;
    bool prev = false;
    int len = 0;
    for (int i = 0 ; i < s.size() ; i++) {
        if (i == 0) {
            if (s[0] == '0') continue;
            if (s[0] == '1') prev = true; len++; 
            continue;
        }
        if (s[i]-'0' == 1) {
            len++;
        } 
        if (prev && s[i]-'0' == 0) {
            lengths.push_back(len);
            len = 0;
        } 
        prev = s[i]-'0' == 1;
    }
    if (prev) {
        lengths.push_back(len);
    }
    sort(lengths.begin(), lengths.end());
    int ans = 0;
    for (int i = lengths.size()-1; i >= 0; i -= 2) {
        ans += lengths[i];
    }
    cout<<ans<<endl;
}

int main()  {
    cin >> n;
    while (n--) solve();
}