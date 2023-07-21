#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    int s = 0;
    int k = 0;
    for (int i = 0 ; i < n ; i++) { 
        cin >> v[i];
        s = max(s+v[i]-1, 0);
        if (v[i] == 0) k = i;
    }

    vector<int> next(n);
    vector<int> prev(n);
    int l = k;
    for (int i = 1 ; i < n+1 ; i++) {
        int j = (k+i)%n;
        if (v[j] == 0) {
            next[l] = j;
            prev[j] = l;
            l = j;
        }
    }
    
    int z = 0;
    for (int i = 0 ; i < n ; i++) {
        if ( s == 0 ) {
            z = i;
            break;
        }
        s = max(z+v[i]-1, 0);
    }

    int cur = next[z];
    cout << " " << z << endl;
    long long ans = 0;
    for (int a = 0 ; a < n ; a++) {
        int i = (z+a+1)%n;
        if (cur == i) {
            cout << cur << "-> " << next[cur] << endl;
            cur = next[cur];
        }
        if (v[i] > 1) {
            for (int j = 0 ; j < v[i]-1 ; j++) {
                bool change = false;
                if (cur < i) {
                    cur += n;
                    change = true;
                }
                cout << cur << " " << i << endl;
                ans += (cur - i) * (cur - i);
                if (change) cur -= n;
                next[prev[cur]] = next[cur];
                prev[next[cur]] = prev[cur];
                cur = next[cur];
            }
        }
    }
    cout << ans << endl;
}