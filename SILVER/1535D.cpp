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

void solve() {
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;


    int num = 1 << n;

    vector<int> canwin(2 * num, 1);
    auto check = [&](int i) {
        if (s[i] == '1') {
            canwin[i] = canwin[i*2+1];
        } else if (s[i] == '0'){
            canwin[i] = canwin[i*2+2];
        } else {
            canwin[i] = canwin[i*2+1] + canwin[i*2+2];
        } 
        return canwin[i];
    };
    reverse(s.begin(), s.end());
    for (int i = num-2 ; i >= 0 ; i--) {
        check(i);
    }

    

    int q;
    cin >> q;
    while (q--) {
        int match;
        char newval;
        cin >> match >> newval;
        //adjust to back to front;
        match = num - match - 1;
        s[match] = newval;
        while (match) {
            check(match);
            match = (match-1)/2;
        }
        cout << check(0) << endl;

    }
}