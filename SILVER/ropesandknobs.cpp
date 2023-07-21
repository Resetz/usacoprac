#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }

    set<pair<int,int>> s;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if ( i == j ) continue;
            pair<int,int> p = {v[i].first-v[j].first, v[i].second-v[j].second};
            if (p.first < 0) {
                p.first *= -1;
                p.second *= -1;
            }
            if (p.second != 0 && p.first != 0) {
                int g = __gcd(p.first, p.second);
                p.first /= g;
                p.second /= g;
            } else {
                if (p.second == 0) {
                    p.first = 1;
                } else if (p.first == 0) {
                    p.second = 1;
                }
            }
            s.insert(p);
        }
    }
    cout << s.size() << endl;
}