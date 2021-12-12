#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int n, m, l;
vector<int> pf;
vector<int> cows;

bool sim(int k) {
    int current = 0;
    int busesUsed = 0;

    while (current < n) {
        int previous = current;
        while (current-previous+1 < l && current < n && cows[current+1] - cows[previous] <= k) {
            current++;
        }
        //cout << "bus " << previous << " " << current << endl;
        current++;
        busesUsed++;
    }
    //cout << k << " " << busesUsed << endl;
    return busesUsed <= m;
}

int main() {

    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    cin >> n >> m >> l;
    
    cows.resize(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> cows[i];
    }

    sort(cows.begin(), cows.end());

    int high, mid, low;
    high = INT_MAX;
    low = 0;
    
    int ans;

    while (high >= low) {
        mid = (high + low) / 2;

        if (sim(mid)) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}