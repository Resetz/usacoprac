#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
int go(int k) {
    int cur = 0;
    int groups = 0;
    for (int i = 0 ; i < n ; i++) {
        if (v[i] > k) return false;
        cur += v[i];
        if (cur > k) {
            cur = v[i];
            groups++;
        }
    }
    return groups < m;
}

int main() {
    cin >> n >> m;
    priority_queue<int> pq;
    for (int i = 0 ; i < m ; i++) {
        pq.push(0);
    }

    v.resize(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }
    int high = 1000000;
    int low = 0;
    int ans = 0;
    while (high >= low) {
        int mid = low + (high - low)/2;
        //cout << high << " " << mid << " " << low << endl;
        if (go(mid)) {
            high = mid-1;
            ans = mid;
        } else {
            low = mid+1;
        }
    }
    cout << ans << endl;
}