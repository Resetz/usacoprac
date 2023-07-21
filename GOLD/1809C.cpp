#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string ans(int a, int b) {
    if (b > a) {
        return ans(a-1, b-a) + "1000 ";
    } else {
        string ret = "";
        for (int i = 0 ; i < a ; i++) {
            if (i == b-1) {
                ret = ret + "500 ";
            } else if (i == b) {
                ret = ret + "-501 ";
            } else {
                ret = ret + "-1 ";
            }
        }
        return ret;
    }
}

void solve() {
    int a,b;
    cin >> a >> b;
    cout << ans(a,b) << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}