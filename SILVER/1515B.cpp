#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main() {
    fast;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        int temp =num;
        bool done = false;
        if (num % 4 == 0) {
            num = num / 4;
            int sqrtOf = (int) sqrt(num);
            if (sqrtOf * sqrtOf == num) {
                cout << "YES\n";
                done =true;
            }          
        } 
        if (!done && num % 2 == 0) {
            num = temp / 2;
            int sqrtOf = (int) sqrt(num);
            if (sqrtOf * sqrtOf == num) {
                cout << "YES\n";
                done =true;
            }   
        }
        if (!done) {
            cout << "NO\n";
        }

    }
}