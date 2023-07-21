#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int h,l,l1,l2;
    cin >> h >> l >> l1 >> l2;
    h++;
    l++;
    l1 *= l1;
    l2 *= l2;


    unsigned long long ans = 0;
    for (int i = 0 ; i <= h ; i++) {
        for (int j = 0 ; j <= l ; j++) {
            if (i*i + j*j >= l1 && i*i + j*j <= l2 && __gcd(i,j) == 1) {
                //cout << i << " " << j << endl;
                //cout << h-i << " " << l-j << endl;
                if (i == 0 || j == 0) {
                    ans += (h-i)*(l-j);
                } else {
                    ans += (h-i)*(l-j)*2;

                }
            }
        }
    }
    cout << ans << endl;
}