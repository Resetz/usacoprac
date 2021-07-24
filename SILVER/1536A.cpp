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

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        bool done = false;
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            if (num < 0) {
            
                
                done = true;
            } 
        }
        if (!done) {
            cout << "YES\n";
            cout << 101 << endl;
            for (int i = 0; i <= 100; i++) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}