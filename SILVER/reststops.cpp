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
#define stop pair<long long,long long>
#define create(from,taste) make_pair(loc,taste)



using namespace std;

long long n,l;
long long b,f;
long long stops = 0;
vector<pair<long long,long long>> restStops;
long long maxes[1000000] = {0};
//long long pfb[1000000];
//long long pff[1000000];
int main() {
    cin >> l >> n >> f >> b;
    for (long long i = 1; i < n+1; i++) {
        long long fromi, toi;
        cin >> fromi >> toi;
        restStops.push_back(make_pair(fromi,toi));
    }
    sort(restStops.begin(), restStops.end());

    long long gain = f - b;
    long long last = l;
    long long current = n;
    pair<long long,long long> max = make_pair(l, 0);
    long long ans = 0;
    vector<pair<long long,long long>> next;
    
    for (long long i = n-1; i >= 0; i--) {
        if (restStops[i].second > max.second) {
            
            next.push_back(restStops[i]);
            max = restStops[i];
        }
    }  
    //you have to count the reamining time
    long long prev;
    bool first = true;
    bool started = false;
    long long ahead;
    last = 0; // position of the last rest stop
    //long long lastVal = 0;
    for (long long i = next.size()-1; i >= 0; i--) {
        ans += (next[i].first - last) * next[i].second;
        last = next[i].first;
        //lastVal = next[i].second;
    }
    //ans += (l - last) * lastVal;
    cout << ans * gain;
}