#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n, m;

bool go(unsigned long long k) {
    int prev = 0;
    int current = 0;
    int used = 0;

    for (int i = 0; i < n ; i++) {
        current += v[i] - prev;
        if (current >= k) {
            current = 0;
        } else {
            used++;
        }
        prev = v[i];
    }
    //cout << k << " -> " << used << endl;
    return used <= m;
}

int main() {
    unsigned long long l;
    cin >> l >> n >> m;


    v = vector<int>(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    unsigned long long high = l;
    unsigned long long low = 1;
    unsigned long long ans = 0;
    while (high >= low) {
        int mid = low + (high - low) / 2;
        if (go(mid)) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    cout << ans << endl;

}