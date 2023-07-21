#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Compare
{
public:
    bool operator() (pair<int,int> a, pair<int,int> b)
    {
        if (a.second > b.second) {
            return a.first > b.first;
        } else {
            return false;
        }
    }
};

int main() {
    int n,d;
    cin >> n >> d;

    vector<pair<int,int>> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(),v.end());

    set<pair<int,int>, Compare> left;
    set<pair<int,int>, Compare> right;
    int l,r;
    int ans = 0;
    l = 0, r = 0;
    for (int i = 0 ; i < n ; i++) {
        while (l < i && v[l].first + d < v[i].first) {
            l++;
            left.erase(v[l]);
        }
        while (r < n && v[i].first + d >= v[r].first) {
            r++;
            right.insert(v[r]);
        }
        if ((*left.begin()).second >= 2*v[i].second && (*right.begin()).second >= 2*v[i].second) {
            ans++;
        }
        left.insert(v[i]);
        right.erase(v[i]);
    }
    cout << ans << endl;
}