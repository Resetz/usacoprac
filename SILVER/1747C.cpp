#include <iostream>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;

    multiset<int> m;
    int o = 0;
    multiset<int>::iterator oi;
    for (int i = 0; i < n*2; i++) {
        int num;
        cin >> num;
        multiset<int>::iterator temp = m.insert(num);
        if (num > o) {
            o = max(num, o);
            oi = temp;
        }
    }

    m.erase(oi);
    int current = *m.rbegin();
    while (m.size() > 1) {

    }
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}