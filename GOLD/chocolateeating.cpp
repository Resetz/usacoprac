#include <iostream>
#include <vector>
#include <climits>


using namespace std;


int n, m;
vector<int> v;

int go(long long k) {
    long long cur = 0;
    int ind = 0;
    for (int i = 0 ; i < m ; i++) {
        while (cur < k) {
            if (ind == n) {
                return false;
            }
            cur += v[ind];
            ind++;
        }
        cur /= 2;
    }
    return true;
}

int main() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    long high = LONG_MAX;
    long low = 0;
    long ans = 0;
    while (high >= low) {
        long mid = low + (high - low)/2;
        //cout << low << " " << mid << " " << high << endl;
        if (go(mid)) {
            low = mid+1;
            ans = mid;
        } else {
            high = mid-1;
        }
    }
    cout << ans << endl;
}