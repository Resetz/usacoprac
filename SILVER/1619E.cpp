#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int total = 0;
    for (int i = 0 ; i < n ; i++) {

    }
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}