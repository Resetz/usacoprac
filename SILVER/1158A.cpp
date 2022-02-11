#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned long long n,m;
    cin >> n >> m;

    unsigned long long sumn = 0;
    unsigned long long maxn = 0;
    unsigned long long maxn2 = 0;
    for (int i = 0 ; i < n ; i++) {
        unsigned long long num;
        cin >> num;
        sumn += num;
        if (num > maxn) {
            maxn2 = maxn;
            maxn = num;
        } else if (num > maxn2) {
            maxn2 = num;
        }
    }

    unsigned long long summ = 0;
    unsigned long long minm = -1;
    for (int i = 0 ; i < m ; i++) {
        unsigned long long num;
        cin >> num;
        summ += num;
        minm = minm == -1 ? num : min(minm, num);
    }

    if (maxn > minm) {
        cout << -1 << endl;
        return 0;
    } else if (maxn == minm) {
        cout <<  summ + sumn*(m) - maxn*m << endl;
    } else {
        cout << sumn*m + summ - maxn*(m-1) - maxn2 << endl;
    }

    
}