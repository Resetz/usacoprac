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
vector<int> a;

vector<int> temp;

int main() {
    int num;
    cin >> num;
    while (num--) {
        temp.clear();
        cin >> n;
        for (int i = 0 ; i < n; i++) {
            int m;
            cin >> m;
            temp.push_back(m);
        }
        sort(temp.begin(), temp.end());

        int maxi = 0;
        int diff = 0;

        int prev = temp[0];
        int count = 0;
        for (int i = 0 ; i < n; i++) {
            if (temp[i] == prev) {
                count++;
            } else {
                maxi = max(maxi, count);
                diff++;
                count = 1;
                prev = temp[i];
            }
        }
        maxi = max(maxi, count);
        diff++;
        cout << max(min(diff, maxi-1), min(diff-1, maxi)) << endl;
    }

}