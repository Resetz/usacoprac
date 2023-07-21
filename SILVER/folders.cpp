#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m, k;
    cin >> m >> n >> k;
    

    //ob 1: we can only place in the first k folders

    vector<int> files(n);
    vector<int> fcnt(m);
    vector<int> current(m, 0);
    for (int i = 0; i < n ; i++) {
        cin >> files[i];
        fcnt[files[i]-1]++;
    }

    vector<bool> filed(n, false);
    int pos = 1;
    for (int i = 0 ; i < n ; i++) {
        if (files[i] >= pos && files[i] <= pos+k-1) {
            filed[files[i]-1] = true;
            current[files[i]-1]++;
        } 
        
        if (current[pos-1] == fcnt[pos-1]) {
            if (pos + k > n) {continue;}
            pos++;
        }
    }

    vector<int> have(m, 0);
    int c = 0;
    for (int i = n-1 ; i >= 0 ; i--) {
        if (filed[files[i]-1]) continue;
        if (files[i] >= pos && files[i] <= pos+k-1) {
            filed[files[i]-1] = true;
            current[files[i]-1]++;
        } else {
            have[files[i]-1]++;
            c++;
        }

        if (c == k) {
            cout << "NO" << endl;
            return;
        }

        if (current[pos-1] == fcnt[pos-1]) {
            if (pos + k > n) {continue;}
            pos++;
            current[pos+k-1] += have[pos+k-1];
            c -= have[pos+k-1];
        }
    }
    cout << "YES" << endl;
    
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}