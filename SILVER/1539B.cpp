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
    int m;
    cin >> n >> m;

    string s;
    cin >> s;
    int pref[100001] = {0};
    for (int i = 0 ; i < n; i++) {
        pref[i+1] = pref[i] + s[i]-'a'+1;
        //cout << pref[i+1] << " ";
    }
    //cout << endl;
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << pref[b] - pref[a-1] << endl;
    }
}