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

int n;
int arr[80000];

int main() {
    cin >> n;
    long long ans[80000] = {0};
    stack<int> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    q.push(n-1);
    for (int i = n-2; i >= 0; i--) {
        while (q.size() > 0) {
            int p = q.top();
            if (arr[p] < arr[i]) {
                ans[i] += 1 + ans[p];
                q.pop();
            } else {
                break;
            }
        }    
        q.push(i);
    
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ans[i];
    }
    cout << sum;
}