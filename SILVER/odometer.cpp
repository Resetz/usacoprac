// Problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=430
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
 
string from, to;
string checking;
int main() {
    cin >> from >> to;
    while (from.size() < 17) {
        from = '0' + from;
    }
    while (to.size() < 17) {
        to = '0' + to;
    }
    //cout << from << " " << to << endl;
    int ans = 0;
    for (int i = 3; i <= 17; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                
                if (k == j) {
                    continue;
                }
                
                for (int pos = 0; pos < i; pos++) {
                    if (j==0 && pos != 0) {
                        continue;
                    }
                    if (k==0 && pos == 0) {
                        continue;
                    }
                    checking = "";
                    for (int m = 0; m < i; m++) {
                        if (m == pos) {
                            checking += k + '0';
                        } else {
                            checking += j + '0';
                        }
                    }
                    
                    while (checking.size() < 17) {
                        checking = '0' + checking;
                    }
                    //cout << checking << endl;
                    if (checking >= from && checking <= to) {
                        //cout << from << " " << checking << " " << to << "(" << k << ", " << j << ")" << endl;
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;
}

