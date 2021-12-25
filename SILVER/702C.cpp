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
    for (int i = 0 ; i < n ; i++) {
        int a, b;
        if (cities[i] <= low) {
            a = low - cities[i];
        } else {
            set<int>::iterator it = towers.lower_bound(cities[i]);
            if (it != towers.begin()) it--;
            a = cities[i] - *it;
        }
        //cout << " " << cities[i] << " ";

        if (cities[i] >= high) {
            b = cities[i] - high;
        } else {
            b = *towers.lower_bound(cities[i]) - cities[i];
        }
        
        //cout << a << " " << b << endl;
        if (a < 0) {
            a = INT_MAX;
        }
        if (b < 0) {
            b = INT_MAX;
        }
        ans = max(ans, min(a,b));
        //ans = max(ans, max(cities[i] - *towers.lower_bound(cities[i]), *towers.upper_bound(cities[i]) - cities[i]));
    }
    cout << ans << endl;
}