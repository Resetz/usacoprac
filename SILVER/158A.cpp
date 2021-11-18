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
int k;

int main() {
    cin >> n >> k;
    vector<int> scores;
    for (int i = 0 ; i < n; i ++) {
        int num;
        cin >> num;
        scores.push_back(num);
    }
    sort(scores.begin(), scores.end());
    int best = scores[n-k];
    int ans = 0;
    for (int i = 0 ; i < n; i++) {
        if (scores[i] > 0 && scores[i] >= best) {
            ans++;
        }
    }
    cout << ans;
    ans;
}