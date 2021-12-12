// time-limit: 1000
// problem-url: https://cses.fi/problemset/task/1641

#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    map<int, int> m;
    vector<int> arr;
    arr.resize(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> arr[i];
        m[k-arr[i]] = i;
    }

    for (int i = 0 ; i < n ; i ++) {
        for (int j = i+1 ; j < n ; j ++) {
            if (m.find(arr[i]+arr[j]) != m.end() && !(m[arr[i]+arr[j]] == i || m[arr[i]+arr[j]] == j)) {
                
                cout << i+1 << " " << j+1 << " " << m[arr[i]+arr[j]]+1 << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}