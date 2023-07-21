#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n,t,k;
    cin >> n >> t >> k;
    vector<int> v(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 0) {
            if (++s == k) {
                s = 0;
                t++;
            }
        } else {
            s = 0;
            t -= v[i];
        }
    }
    cout << t << endl;
}