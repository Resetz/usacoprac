#include <iostream>
#include <string>
#include <fstream>
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
    ifstream f;
    
    f.open("include.l");
    vector<string> v;
    while (!f.eof()) {
        string s;
        getline(f, s);
        v.push_back(s);
        cout << "got " << s << endl;
    }
    sort(v.begin(), v.end(), [](string a, string b) -> int {
        return sin(((double)a.size()) / 5) > sin(((double)b.size()) / 5);
    });
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}