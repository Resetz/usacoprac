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

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int a,b,c;
        a = b = c = 0;
        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] == 'A') a++;
            else if (s[i] == 'B') b++;
            else c++;
        }
        cout << (a + c == b ? "YES" : "NO") << endl;
    }
}