#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, base[N];
vector<int> items[N];

int main() {

    cin >> n;

    int placed = 0, ans = n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        // impossible to add this plate
        cout << x << " " << placed << endl;
        if (x < placed) {
            ans = i;
            break;
        }
        // plates that go on this stack
        for (int j = x; j > 0 && !base[j]; j--) {
            base[j] = x;
        }
        // remove plates with smaller labels
        if (!items[base[x]].empty()) {
            cout << x << " placing " << items[base[x]].back() << endl;
        }
        while (!items[base[x]].empty() && items[base[x]].back() < x) {
            placed = items[base[x]].back();
            cout << "placed is now " << placed  << " | popped " << items[base[x]].back() << endl;
            items[base[x]].pop_back();
        }
        // add this plate to the stack
        items[base[x]].push_back(x);
    }

    cout << ans << endl;

}