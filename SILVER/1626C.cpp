#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<pair<int,int>> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first;
    }
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].second;
    }


    vector<pair<pair<int,int>,int>> check;
    for (int i = 0 ; i < n ; i++) {
        check.push_back({{v[i].first, 1}, v[i].second});
        check.push_back({{v[i].first-v[i].second+1, 0}, 1});
    }

    sort(check.begin(), check.end());

    int first = check[0].first.first;
    int last = check[0].first.first;
    int found = 1;

    unsigned long long ans = 0;
    for (int i = 1 ; i < check.size() ; i++) {
        if (check[i].first.second == 0) {
            // must be at least greater than one
            if (found == 0) {
                unsigned long long dist = last - first + 2;
                ans += (dist*(dist-1))/2;
                first = check[i].first.first;
                last = check[i].first.first;
                found++;
            }
            else {
                found++;
            }
        } 
        else if (check[i].first.second == 1) {
            found--;
        }
        last = check[i].first.first;
    }

    unsigned long long dist = last - first + 2;
    ans += (dist*(dist-1))/2;

    cout << ans << endl; 
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}