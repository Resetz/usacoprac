#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    
    if (n % 2== 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> sums((n*(n+1))/4+1);

    sums[0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = sums.size()-1 ; j >= 0; j--) {
            if (j+i >= sums.size()) continue;
            if (sums[j] != 0) sums[j+i] += sums[j];
        }
    }
    cout << sums[sums.size()-1]/2 << endl;
}