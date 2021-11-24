#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    int n;
    unsigned long long b;
    int cur = 0;
    map<int,int> s;
    cin >> n >> b;

    for (int i = 0; i < n ; i++) {
        int num;
        cin >> num;
        num = num << i;
        cur |= num;
    }
    unsigned long long amt = 0;
    while (s.find(cur) == s.end()) {
        if (amt == b) {
           for (int i = 0 ; i < n ; i++) {
               cout << ((cur >> i) & 1) << endl;
           } 
           return 0;
        }

        for (int i = 0 ; i < n ; i++) {
            cerr << ((cur >> i) & 1) << " ";
        } 
        cerr << endl;
        s[cur] = amt;
        amt++;
        int prev = cur;
        for (int i = 0 ; i < n-1 ; i++) {
            cur ^= ((prev >> i) & 1) << (i+1);  
        }
        cur ^= ((prev >> (n-1)) & 1);
    }
    int go = (b-s[cur]) % ((amt) - s[cur]) + s[cur];
    for (int i = 0 ; i <= 65536 ; i++) {
        if (s[i] == go) {
            for (int j = 0 ; j < n ; j++) { 
                cout << ((i >> j) & 1) << endl;
            }
        }
    }
}