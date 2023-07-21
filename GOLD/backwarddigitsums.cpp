#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0 ; i < n ;i++) v[i] = i+1;


    while (next_permutation(v.begin(), v.end())) {
        vector<int> cur = v;

        for (int i = n; i > 1 ; i--) {
            for (int j = 0; j < i ; j++) {
                cur[j] = cur[j]+cur[j+1];
            }
        }
        if (cur[0] == k) {
            for (int i = 0 ; i < n ;i++) {
                cout << v[i] << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}