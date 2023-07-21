/*
January: 31 days
February: 28 days and 29 in every leap year
March: 31 days
April: 30 days
May: 31 days
June: 30 days
July: 31 days
August: 31 days
September: 30 days
October: 31 days
November: 30 days
December: 31 days
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v(365, 0);
    int n;
    cin >> n;

    vector<int> d = {31,28,31,30,31,30,31,30,31,30,31,30};
    for (int i = 0 ; i < n ; i++) {
        int a,b,c; cin >> a >> b >> c;
        a--;b--;
        for (int j = 0 ; j < a; j++) {
            b += d[j];
        } 
        while (b < 365) {
            v[b] = true;
            b+=c;
        }
    }
    int ans = 0;
    int prev = -1;
    for (int i = 1 ; i < 365 ; i++) {
        if (v[i]) {
            //cout << i << " " << prev << endl;
            ans = max(ans, i-prev-1);
            prev = i;
        }
    }
    ans = max(ans, 364-prev);
    cout << ans << endl;
}