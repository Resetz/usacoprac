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


int t,n;
int arr[100];
int ans[100];

void solve() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    queue<pair<pair<int,int>, int>> q;
    
    q.push(make_pair(make_pair(0, n-1), 0));
    while (!q.empty()) {
        pair<pair<int,int>,int> p = q.front();
        q.pop();

        if (p.first.first > p.first.second) {
            continue;
        }
        if (p.first.first == p.first.second) {
            ans[p.first.first] = p.second;
        }
        else  {
            int biggest = -1;
            int index = 0;
            for (int i = p.first.first; i <= p.first.second; i++) {
                if (arr[i] > biggest) {
                    index = i;
                    biggest = arr[i];
                }
            }
            ans[index] = p.second;
            q.push(make_pair(make_pair(p.first.first, index-1), p.second + 1));
            q.push(make_pair(make_pair(index+1, p.first.second), p.second + 1));
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> t;
    while (t--) solve();
}