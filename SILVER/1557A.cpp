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
using namespace std;

#define all(n) n.begin(), n.end()
using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << fixed << setprecision(10);
    long double sum = 0;
    long double maxi = -(10e9) - 1;
    for (int i = 0 ; i < n ; i++) {
        long double num;
        cin >> num;
        sum += num;
        maxi = max(num, maxi);
    }
    //cout << sum << " " << maxi << endl;
    cout << ((sum - maxi) / (n-1)) + maxi << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin >> n;
    while (n--) solve();
}