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


int n;
int m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        vector<int> arr;
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        sort(arr.begin(), arr.end());

        bool done = false;
        for (int j = 1 ; j < m; j++) {
            if (arr[j] - arr[j-1] > 1) {
                cout << "NO";
                done = true;
                break;
            }
        }
        if (!done) {
            cout << "YES";
        }
        cout << endl;

    }
}