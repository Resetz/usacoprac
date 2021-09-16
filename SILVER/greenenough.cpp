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

int dat[500][500];
int arr[500][500];
int n;
unsigned long long findsquares() {
    unsigned long long ans = 0;
    for (int i = 0 ; i < n ; i++) {
        vector<int> cont(n, 1);
        for (int j = i ; j < n ; j++) {
            unsigned long long run = 0;
            for (int k = 0 ; k < n ; k++) {
                cont[k] = cont[k]&arr[j][k];
                if (cont[k]) run++;
                else run = 0;
                ans += run;
            }
        }
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            unsigned long long l = 0;
            cin >> l;
            if (l < 100) {
                dat[i][j] = 0;
            } else if (l == 100) {
                dat[i][j] = 1;
            } else {
                dat[i][j] = 2;
            }
        }
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            arr[i][j] = dat[i][j] == 0 ? 0 : 1;
        }
    }
    unsigned long long ans = findsquares();

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            arr[i][j] = dat[i][j] == 2 ? 1 : 0;
        }
    }

    ans -= findsquares();
    cout << ans << endl;
}