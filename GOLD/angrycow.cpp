#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<float> r(n-1);
    vector<float> l(n-1);

    int trailing = 0;
    for (int i = 1 ; i < n ; i++) {
        r[i-1] = min(r[i]+1, (float)(v[i] - v[i-1])/2);
        while (trailing + 1 < i && (float)(v[i] - v[trailing] > r[trailing])) {
            trailing++;
        }
    }
    trailing = n-1;
    for (int i = n-1 ; i >= 0 ; i--) {
        while (trailing - 1 > i && (float)(v[trailing] - v[i] > r[trailing])) {
            trailing--;
        }
        l[i] = min(l[i]+1, (float)(v[i+1] - v[i]/2));
    }

    int i, j;
    int ans = INT_MAX;
    while (j > i) {
        ans = min(ans, max());
    }
}