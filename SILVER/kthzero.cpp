#include <bits/stdc++.h>


using namespace std;
int k;
int n, t;

int main() {
    
    cin >> n >> t;
    cin >> k;

    int low = 0;
    int middle = (n+1)/2;
    int high = n-1;

    int zeroes = 0;
    int totalZeroes;
    bool first = true;
    if (n == 2) {
        cout << "? " << 1 << " " << 1 << endl;
        cin >> zeroes;
        if (zeroes == 1) {
            cout << "! 2";
        } else {
            if (k == 1) {cout << "! 1";}
            else {cout << "! 2";}
        }
    }  else {
        cout << "? " << 1 << " " << n << endl;
        cin >> zeroes;
        totalZeroes = n - zeroes;
        int ans = 1;
        while (high >= low) {
            middle = (high+low)/2;
            cout << "? " << 1 << " " << middle+1 << endl;
            cin >> zeroes;
            zeroes = (middle+1) - zeroes;
            if (zeroes >= k) {
                ans = middle;
                high = middle-1;
            } else {
                
                low = middle+1;
            }
        }
        cout << "! " << ans+1;
    }

}