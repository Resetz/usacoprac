#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    int n = 0;
    int cur = 0;
    int num = 0;
    while (cin >> num) {
        num = num << n;
        cur |= num;
        n++;
    }

    n = 12;
    int prev = cur;
    for (int i = 0 ; i < n-1 ; i++) {
        cur ^= ((prev >> i) & 1) << (i+1);  
    }
    cur ^= ((prev >> (n-1)) & 1);
    cout << endl;

    for (int i = 0 ; i < n ; i++) {
        cerr << ((prev >> i) & 1) << " ";
    } 
    cout << endl;
    for (int i = 0 ; i < n ; i++) {
        cerr << ((cur >> i) & 1) << " ";
    } 
    cerr << endl;
}