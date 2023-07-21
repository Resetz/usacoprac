#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    #define int long long

    int n,t; 
    cin >> n >> t;

    vector<pair<int,int>> days(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> days[i].first >> days[i].second;
    }
    days.push_back({t, INT_MAX}); //INT_MAX is representative of infinity.
    sort(days.begin(), days.end());
    int ans = 0;
    int b = 0;
    int prev = 0;

    for (int i = 0 ; i < n+1 ; i++) {
        if (days[i].second == INT_MAX) {
            if (b > 0) ans++;
            break;
        }

        int balesToEat = min(days[i].first - prev, b);

        b += days[i].second;
        b -= balesToEat;

        prev = days[i].first;

        ans += balesToEat;
    }
    cout << ans << endl;
}