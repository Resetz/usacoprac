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

using namespace std;

set<int> visited;
string current = "";
int num = 0;
string s[7] = {"", "", "", "", "", "", ""};
bool used[7] = {false};
int n;

int ans = 50;

int g = 1;


string concat(string a, string b) {
    int app;

    string ret = a;
    int go = 0;
    for (app = 0 ; app < min(a.size(), b.size()) ; app++) {
        string sub = a.substr(a.size()-1-app);
        if (sub == b.substr(0,app+1)) go = app+1;
    }
    app = go;
    for (int i = app; i < b.size() ; i++) { 
        ret += b[i];
    }
    return ret;
}

bool check(int c, int i) {
    while (c > 0) {
        if (c % 10 == i) return false;
        c /= 10;
    }
    return true;
}
void dfs(int next) {
    num *= 10;
    num += next + 1;
    if (visited.find(num) == visited.end() && !used[next]) {
        visited.insert(num);
        used[next] = true;

        string prev = current;
        current = concat(current, s[next]);
        //cout << current << endl;

        if (num > g) {
            ans = min(ans, (int) current.size());
            current = prev;
            used[next] = false;
            num /= 10;
            return;
        }

        for (int i = 0 ; i < n ; i++) {
            if (!used[i]) dfs(i);
        }

        current = prev;
        used[next] = false;

    }
    num /= 10;
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) { 
        cin >> s[i]; 
        g *= 10; 
    };
    g /= 10;
    for (int i = 0; i < n; i++) { dfs(i); num = 0;};
    //cout << concat("tac", "aca");
    cout << ans << endl;

}