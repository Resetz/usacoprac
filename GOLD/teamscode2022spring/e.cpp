#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    pair<long long,long long> pos = {0,0};
    long long a,b,c,d;
    a=b=c=d = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'U') {
            pos.first++;
        } else if (s[i] == 'D') {
            pos.first--;
        } else if (s[i] == 'R') {
            pos.second++;
        } else {
            pos.second--;
        }
        a = max(pos.first, a);
        b = max(pos.second, b);
        c = min(pos.first, c);
        d = min(pos.second, d);
    }
    cout << (abs(a-c)+1) * (abs(b-d)+1) << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}