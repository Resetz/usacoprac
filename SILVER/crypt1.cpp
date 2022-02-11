/*
ID: vincent97
TASK: crypt1
LANG: C++                 
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int> available;
int n;

bool check(int num) {
    while (num > 0) {
        if (!available[num%10]) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {

    #ifndef LOCAL
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    #endif

    cin >> n;
    v.resize(n);
    available.resize(10, false);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
        available[v[i]] = true;
    }

    int ans = 0;
    for (int i1 = 0; i1 < n ; i1++) {
        for (int i2 = 0; i2 < n ; i2++) {
            for (int i3 = 0; i3 < n ; i3++) {
                for (int i4 = 0; i4 < n ; i4++) {
                    for (int i5 = 0; i5 < n ; i5++) {
                        bool good = true;
                        int n1 = v[i1] + v[i2]*10 + v[i3]*100;
                        int n2 = v[i4] + v[i5]*10;
                        if (v[i4] * n1 < 1000 && v[i5] * n1 < 1000 && 
                            v[i4] * n1 >= 100 && v[i5] * n1 >= 100 &&
                            check(v[i4] * n1) && check(v[i5] * n1)) {
                            int newnum = n1*n2;
                            if (newnum < 10000) {
                                if (check(newnum)) { 
                                    ans++;
                                }
                            }
                        } 

                    }
                }
            }
        }
    }
    cout << ans << endl;
}