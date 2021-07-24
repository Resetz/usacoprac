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

#define mp make_pair
#define ll long long
#define pII pair<int,int>
#define pLL pair<long long, long long>

using namespace std;
int n;

set<pair<pair<int,int>,char32_t>> visited;

int main() {
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int x = 0;
        int y = 0;
        long long time = 0;
        visited.clear();
        for (int i = 0; i < s.size(); i++) {
            if (visited.find(make_pair(make_pair(x,y), s[i])) == visited.end()) {
                time += 5;
            } else {
                time += 1;
            }
            visited.insert(make_pair(make_pair(x,y), s[i]));
            if (s[i] == 'N') {
                y--;
                visited.insert(make_pair(make_pair(x,y), 'S'));
            } else if (s[i] == 'S') {
                y++;
                visited.insert(make_pair(make_pair(x,y), 'N'));
            } else if (s[i] == 'E') {
                x++;
                visited.insert(make_pair(make_pair(x,y), 'W'));
            } else if (s[i] == 'W') {
                x--;
                visited.insert(make_pair(make_pair(x,y), 'E'));
            }
            
            
            
            
            
        }
        cout << time << endl;
    }
}