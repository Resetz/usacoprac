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

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)

long getValueOf(string s) {
    long ret = 0;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == 'A' || ch == 'B' || ch == 'C') {
            ret = ret*10+2;
        } else if (ch == 'D' || ch == 'E' || ch == 'F') {
            ret = ret*10+3;
        } else if (ch == 'G' || ch == 'H' || ch == 'I') {
            ret = ret*10+4;
        } else if (ch == 'J' || ch == 'K' || ch == 'L') {
            ret = ret*10+5;
        } else if (ch == 'M' || ch == 'N' || ch == 'O') {
            ret = ret*10+6;
        } else if (ch == 'P' || ch == 'R' || ch == 'S') {
            ret = ret*10+7;
        } else if (ch == 'T' || ch == 'U' || ch == 'V') {
            ret = ret*10+8;
        } else if (ch == 'W' || ch == 'X' || ch == 'Y') {
            ret = ret*10+9;
        }
    }
    //cout << ret;
    return ret;
}


int i, j, k;
long n, m;

string names[5000];

int main() {
    fast;
    
    cin >> n;

    //cout << n;
    string in;
    bool counted = false;
    while (cin >> in) {
        if (n == getValueOf(in)) {
            counted = true;
            cout << in << "\n";
        }
    }
    if (!counted) {
        cout << "NONE";
    }

    
    
}