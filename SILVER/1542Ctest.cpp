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
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_set>

#define all(n) n.begin(), n.end()
using namespace std;

int solve(int num) {
    int i = 1;
    while (true) {
        if (num % i != 0 || i > num) return i;
        i++;
    }

}

int main() {
    unordered_set<int> seen = {};
    for (int i = 1; i < 1000; i++) {
        
        if (seen.find(solve(i)) == seen.end()) {
            cout << i << ". " << solve(i) << " ";\
            cout << endl;
        }
        
        seen.insert(solve(i));
    } 
    int num = -1;
    do {
        cin >> num;
        cout << " > " << solve(num) << endl;
    } while (num != -1);
}