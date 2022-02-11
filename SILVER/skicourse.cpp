/*
ID: vincent97
TASK: skidesign
LANG: C++                 
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    #ifndef LOCAL
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> v(101);
    for (int i = 0; i < n ; i++) {
        int num;
        cin >> num;
        v[num]++;
    }

    long long ans = -1;
    for (int l = 0 ; l < 101-17 ; l++) {
        int r = l+17;

        long long result = 0;
        for (int i = 0 ; i < l ; i++) {
            result += (l - i)*(l - i) * v[i];
        }
        for (int i = 100 ; i > r ; i--) {
            result += (i - r)*(i - r) * v[i];
        }
        if (ans == -1 || result < ans) {
            ans = result;
        }
    }
    cout << ans << endl;
    
}