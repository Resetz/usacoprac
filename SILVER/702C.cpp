#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> cities;
    set<int> towers;

    for (int i = 0 ; i < n ; i++) {
        int num;
        cin >> num; cities.push_back(num);
    } 
    int high = -INT_MAX;
    int low = INT_MAX;
    for (int i = 0 ; i < k ; i++) {
        int num = 0;
        cin >> num;
        high = max(high, num);
        low = min(low, num);
        towers.insert(num);
    }

    int ans = -1;
    for (int i = 0 ; i < k ; i++) {
        if (towers.lower_bound(cities[i]) == towers.end()) {
            ans = max(ans, cities[i] - high);
        } else {
            ans  = max(ans, cities[i] - high);
            
        }
        ans = max(ans, max(cities[i] - *towers.lower_bound(cities[i]), *towers.upper_bound(cities[i]) - cities[i]));
    }
    cout << ans << endl;
}