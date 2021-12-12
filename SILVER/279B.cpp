#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> v;
    
    v.resize(n); 
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    int maxl = 0;
    int r = 0;
    int cur = 0;
    int total = v[0];
    for (int l = 0 ; l < n ; l++) {
        bool found = false;
        while (true) {
            if (r+1 >= n || v[r+1] + total > t) {
                break;
            }
            r++;
            found = true;
            total += v[r];
        }
        if (r+1 >= n) {
            if (total < t) {
                maxl = max(r-l+1, maxl);
            }
        }
        if (found) maxl = max(r-l+1, maxl);
        total -= v[l];
    }
    cout << maxl << endl;
}