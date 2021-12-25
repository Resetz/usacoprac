#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct {
    int day, cow, amt;
} event;

int main() {

    #ifndef LOCAL
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;
    
    vector<event> events;
    map<int, int> cowAmts; // key: cow | value: amount of milk produced
    multiset<int> amts; // hold amounts | used to find max milk produced
    map<int, int> numAmts; // key: amount of milk produced | value: how many cows produce that much milk

    cowAmts[-1] = k;
    amts.insert(k);
    numAmts[k] = 1;
    for (int i = 0 ; i < n ; i++) {
        int day, cow, amt;
        cin >> day >> cow >> amt;
        cow--;
        events.push_back({day, cow, amt});
    }
    sort(events.begin(), events.end(), [](event a, event b) -> bool { return a.day < b.day; });

    int curMax = *amts.rbegin();
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {

        if (cowAmts.find(events[i].cow) == cowAmts.end()) {
            cowAmts[events[i].cow] = k;
            amts.insert(k);
            numAmts[k]++;
        }

        int last = numAmts[curMax];
        int prev = cowAmts[events[i].cow];
        int prevNum = numAmts[cowAmts[events[i].cow]];
        cowAmts[events[i].cow] += events[i].amt;

        //add
        amts.insert(cowAmts[events[i].cow]);
        if (numAmts.find(cowAmts[events[i].cow]) == numAmts.end()) {
            numAmts[cowAmts[events[i].cow]] = 1;
        } else {
            numAmts[cowAmts[events[i].cow]]++;
        }

        //sub
        amts.erase(amts.lower_bound(prev));
        numAmts[prev]--;
        if (*amts.rbegin() != curMax) {
            if (prev == curMax && prevNum == 1 && numAmts[*amts.rbegin()] == 1 && *amts.rbegin() == cowAmts[events[i].cow]) {
                curMax = *amts.rbegin();
                continue;
            }
            ans++;
            curMax = *amts.rbegin();
        } else if (last != numAmts[curMax]) {
            ans++;
        }

        //cout << endl;
    }
    cout << ans << endl;
}