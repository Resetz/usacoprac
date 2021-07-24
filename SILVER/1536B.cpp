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

bool checked[18279];

#define bump1 26
#define bump2 26*26

void solve() {
    for (int i = 0 ; i < 18279 ; i++) {
        checked[i] = false;
    }
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        checked[s[i]-'a'] = true;
    }

    for (int i = 0; i < n-1; i++) {
        checked[(s[i]+1-'a')*26+(s[i+1]-'a')] = true;
    }

    for (int i = 0 ; i < n-2; i++) {
        checked[(s[i]+1-'a')*26*26+(s[i+1]+1-'a')*26+(s[i+2]-'a')] = true;
    }
    
    int i = 0;
    while (checked[i]) {
        i++;
    }
    if (i < 26) {
        cout << (char) (i+'a');
    }
    else if (i < 26*26) {
        cout << (char)( (i/26)-1+'a') << (char)( i%26+'a');
    } else {
        cout << (char)( (i/(26*26))-1+'a') << (char)( ((i/26)%26)-1+'a') << (char)( i%26+'a');
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();   
}