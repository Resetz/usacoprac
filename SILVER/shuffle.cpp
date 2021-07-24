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
int potentialCows[100000];
int to[100000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        to[i] = m-1;
        potentialCows[to[i]]++;
    }
    //check which ones are zero

    queue<int> q;
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (potentialCows[i] == 0) {
            q.push(i);
            ans--;
        }
    }
    
    while (q.size() != 0) {
        int cow = q.front();
        q.pop();
        potentialCows[to[cow]]--;
        if (potentialCows[to[cow]] == 0) {
            q.push(to[cow]);
            ans--;
        }
    }
    cout << ans;
}