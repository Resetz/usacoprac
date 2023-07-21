#include <iostream>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> l((n+1)/2);
    vector<pair<int,int>> r(n/2);

    for (int i = 0 ; i < n ; i++) {
        long long f, t;
        cin >> f >> t;
        if (i > n/2) {
            r[i-n/2] = {f,t};
        } else {
            l[i] = {f,t};
        }
    }

    for (int i = 0;  i < n ; i++) {
        
    }

}