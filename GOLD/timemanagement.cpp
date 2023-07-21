#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end());

    int time = 0;
    int skip = INT_MAX;
    for (int i = 0 ; i < n ; i++) {
        time += v[i].second;
        skip = min(skip, v[i].first - time);
        if (time > v[i].first) {
            cout << "-1";
            return 0;
        }
    }
    
    cout << skip << endl;
}