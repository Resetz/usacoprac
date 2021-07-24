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

string to;
string from;

string s[25000];

bool check(string s1, string s2) {
    bool found = false;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            if (!found) {
                found = true;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> from;
    cin >> to;

    string m;
    int words = 0;
    while (cin >> m) {
        if (m.size() == from.size()) {
            s[words] = m;
            words++;
        }
    }
    words++;
    bool visited[25000];
    queue<pair<string, int>> q;
    pair<string, int> p(from, 0);
    q.push(p);
    while (true) {
        pair<string, int> p = q.front();
        q.pop();
        if (p.first.compare(to) == 0) {
            cout << p.second;
            return 0;
        }
        for (int i = 0; i < words; i++) {
            if (!visited[i] && check (p.first, s[i])) {
                visited[i] = true;
                q.push(make_pair(s[i], p.second + 1));
            }
        }
    }
}