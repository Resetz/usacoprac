
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
int i;
bool visited[3000000] = {false};
vector<pair<int, pair<int,int>>> q;
int main() {
    cin >> n;

    q.push_back(make_pair(1, make_pair(0, -2)));
    while (true) {
        pair<int, pair<int, int>> p = q[0];
        if (p.first == n) {
            cout << p.second.first;
            return 0;
        }
        q.erase(q.begin());
        
        cout << p.first << " " << p.second.first << endl;
        
        if ( p.first+1 < n && !visited[p.first+1] && p.second.second != 2) {
            cout << "Case 1:" << endl;
            q.push_back(make_pair(p.first+1, make_pair(p.second.first + 1, 1)));
            visited[p.first+1] = true;
        }
        if (p.first*3 < n+3 && !visited[p.first*3]) {
            cout << "Case 2:" << endl;
            q.push_back(make_pair(p.first*3, make_pair(p.second.first + 1, 0)));
            visited[p.first*3] = true;
        }
        if (p.first-1 >= 0 && !visited[p.first-1] && p.second.second != 1) {
            cout << "Case 3:" << endl;
            q.push_back(make_pair(p.first-1, make_pair(p.second.first + 1, 2)));
            visited[p.first-1] = true;
        }
    }
}