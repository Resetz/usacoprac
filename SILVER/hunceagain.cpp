#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> v;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n ; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0 ; i < n  ; i++) {
        cout << v[i] << " ";
    }
    cerr << "a" << endl;
}