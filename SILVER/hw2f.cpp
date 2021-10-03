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
#include <unordered_map>

#define all(n) n.begin(), n.end()
using namespace std;

int main() {
    vector<int> perm = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> yes(6, vector<int>());

    
    while (next_permutation(all(perm))) {
        if (perm[0] != 1) {
            break;
        } 
        int f = perm[0] * perm[5] + perm[1];
        int g = perm[2] * perm[6] * perm[6] - perm[3] * perm[6] + perm[4];
        if ( f == g ) {
            for (int i = 1; i < 7; i++) {
                yes[i-1].push_back(perm[i]);
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        cout << '[';
        for (int j = 0; j < yes[i].size(); j++) {
            cout << yes[i][j] << ", ";
        }
        cout << ']' << endl;
    }
}