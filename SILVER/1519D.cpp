//prac

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
long long a[50000];
long long b[50000];
int main() {
    cin >> n;


    for (int i = 0;i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0;i < n; i++) {
        cin >> b[i];
    }
    long long total = 0;
    for (int i = 0; i < n; i++){
        total += a[i] * b[i];
    }
    long long ans = total;
    //odd
    for (int i = 0; i < n; i++){
        //up;
        //find the number of loops.
        int l = 1;
        long long ltotal = total;
        while (i + l < n && i - l > -1) {
            ltotal -= a[i + l] * b[i + l]; 
            ltotal += a[i - l] * b[i + l]; 
            ltotal -= a[i - l] * b[i - l]; 
            ltotal += a[i + l] * b[i - l]; 
            if (ltotal > ans) {
                ans = ltotal;
            }
            l++;
        }
    }
    //even
    for (int i = 0; i < n; i++){
        //up;
        //find the number of loops.
        int l = 1;
        long long ltotal = total;
        ltotal -= a[i] * b[i];
        ltotal += a[i - 1] * b[i];
        ltotal -= a[i - 1] * b[i - 1];
        ltotal += a[i] * b[i - 1];
        if (ltotal > ans) {
            ans = ltotal;
        }
        while (i + l < n && i - l - 1 > -1) {
            ltotal -= a[i + l] * b[i + l]; 
            ltotal += a[i - l - 1] * b[i + l]; 
            ltotal -= a[i - l - 1] * b[i - l - 1]; 
            ltotal += a[i + l] * b[i - l - 1]; 
            if (ltotal > ans) {
                ans = ltotal;
            }
            l++;
        }
    }
    cout << ans;
}
