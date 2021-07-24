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
int grid[101][101];

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i ++) {
        string s;

        for (int j = 0 ; j < n ; j++) {
            cin >> grid[i][j];
        }
    }
    int sum = 0;
    for (int i = n-1; i >= 0; i--) {
        if (i != n/2) {
            sum+= grid[i][i];
            //cout << grid[i][i] << endl;
            sum+= grid[i][n-i-1];
            //cout << grid[i][n-i-1] << endl;
            sum+= grid[i][n/2];
            //cout << grid[i][n/2] << endl;
        } else {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
                //cout << grid[i][j] << endl;
            }
        }
    }
    cout << sum;
}