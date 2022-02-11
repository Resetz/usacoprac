#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s;
    cin >> s >> n;
    
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    vector<bool> ans(s+1, false);
    ans[0] = true;
    for (int i = 0 ; i < n ; i++) {
        for (int j = s-v[i] ; j >= 0 ; j--) {
            ans[j+v[i]] = ans[j] | ans[j+v[i]];
        }
    }
    for (int j = s ; j >= 0 ; j--) {
        if (ans[j]) {
            cout << j << endl;
            break;
        }
    }
}