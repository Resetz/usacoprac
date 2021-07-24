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
#define SIZE 2*100000+1
int nums[SIZE];
int n;

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i ++) {
        int j;
        cin >> j;
        nums[j]++;
        if (nums[j] == 3) {
            cout << "NO";
            return 0;
        }
    } 
    cout << "YES\n";
    vector<int> v;
    for (int i = 0 ; i < SIZE ; i ++) {
        if (nums[i] > 0) {
            v.push_back(i);
            nums[i]--;
        }
    }
    cout << v.size() << "\n";
    for (int i = 0 ; i < v.size() ; i ++) {
        cout << v[i] << " ";
    }
    cout << "\n";
    v.clear();
    for (int i = SIZE-1 ; i >= 0 ; i --) {
        if (nums[i] > 0) {
            v.push_back(i);
            nums[i]--;
        }
    }
    cout << v.size() << "\n";
    for (int i = 0 ; i < v.size() ; i ++) {
        cout << v[i] << " ";
    }
}