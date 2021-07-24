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
inline bool check(string s, string b) __attribute__((always_inline));


string b;
int len;
string checking;

inline bool check(string s) {
    if (s.size() <= len) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (s[s.size()-i-1] != b[len-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> checking;
    cin >> b;
    len = b.size();
    string add;
    for (int i = 0; i < checking.size(); i++) {
        add += checking[i];
        int same = false;
        bool done = false;
        if (add.size() <= len) {
            same = false;
            done = true;
        } else {

            
            for (int i = 0; i < len; i++) {
                if (add[add.size()-i-1] != b[len-i-1]) {
                    done = true;
                    same = false;
                    break;
                }
            }
        }
        if (!done) {
            same = true;
        }
        if (same) {
            add = add.substr(0, add.size()-len);
        }
    }
    cout << add;
}