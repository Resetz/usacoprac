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
#include <iomanip>

#define all(n) n.begin(), n.end()
using namespace std;

vector<pair<int,int>> cows;

int main() {
    int n, m;
    cin >> n >> m;
    cows.resize(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> cows[i].second >> cows[i].first;     
    }

    multiset<int> ms;
    for (int i = 0 ; i < m ; i++) {
        ms.insert(-1);
    }

    sort(all(cows));
    int ans = 0;
    for (int i = 0 ; i < n ; i ++) {
        multiset<int>::iterator go;
        if ((go = upper_bound(all(ms), cows[i].second)) != ms.begin()) {
            go--;
            ms.erase(go);
            ms.insert(cows[i].first);
            ans++;
        }
    }
    cout << ans << endl;

    
}