#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> v; v.resize(n);
    int go = -1;
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
        if (go == -1) {
            go = v[i]/n;
        } else {
            go = min(go, v[i]/n);
        }
    }
    for (int i = 0; i < n; i++) {
        v[i] -= go * n;
    }
    for (int i = 0 ; i < n ; i++) {
        if (v[i] > i) {
            continue;
        } else {
            cout << i+1;
            return 0;
        }
    }
    for (int i = 0 ; i < n ; i++) {
        if (v[i] > i+n) {
            continue;
        } else {
            cout << i+1;
            return 0;
        }   
    }
    
}