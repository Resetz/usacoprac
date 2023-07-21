#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<unsigned long long,unsigned long long>> v;

int main() {
    int n, coins;
    cin >> n >> coins;
    v.resize(n);
    for (int i = 0 ; i < n ; i++) {
        int c,d,h;
        cin >> c >> d >> h;

        v[i].second = c; v[i].first = d*h;
    }

    sort(v.begin(), v.end());

    vector<int> best(n);
    best[i] = v[0].second;
    for (int i = 0; i < n ; i++) {
        best[
    }
    int m;
    cin >> m;
    for (int i = 0 ; i < n ; i++) {

    }

}