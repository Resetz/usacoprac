
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
int mod;
int initial;
int goal;
bool visited[10000] = {false};
int paints[10000];
vector<pair<int, int>> q;
int main() {
    cin >> initial >> goal;
    cin >> n >> mod;
    for (int i = 0; i < n; i++) {
        cin >> paints[i];
    }
    
    q.push_back(make_pair(initial, 0));

    while (q.size() != 0) {
        pair<int,int> p = q[0];
        q.erase(q.begin());
        if (p.first == goal) {
            cout << p.second;
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[p.first * paints[i] % mod]) {
                q.push_back(make_pair(p.first * paints[i] % mod, p.second + 1));
                visited[p.first * paints[i] % mod] = true;
            }
        }

    }
    cout << -1;
}