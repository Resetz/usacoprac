#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int f = m;
    int t = m;
    //half tru half false
    for (int i = 0 ; i < n ; i++) {
        int k;
        cin >> k;
        f = min(k, f);
        t = min(m-k, t);
    }
    cout << max(f,t) << endl;
}