#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(k+1);

    for (int i = 0 ; i < n ; i++) {
        int num; cin >> num;
        if (num < k) {
            v[num]++;
        }
    }
    for (int i = 1 ; i < k ; i++) {
        //cout << i << " " << v[i] << endl;
        if ((v[i] % (i+1)) != 0) {
            cout << "No" << endl;
            return false;
        } else {
            v[i+1] += v[i]/(i+1);
        }
    }
    cout << "Yes" << endl;
}