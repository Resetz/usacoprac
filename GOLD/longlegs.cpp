#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int a,b;
    cin >> a >> b;
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    vector<int> v((int)sqrt(a) + 1);
    for (int i = 1; i < v.size() ; i++) {
        v[i] = a/i + (i-1);
        if (a % i != 0) {
            v[i]++;
        }
    }

    int k = sqrt(b-a);
    for (int j = 0 ; 
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}