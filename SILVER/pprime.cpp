/*
ID: vincent97
TASK: pprime
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isprime(int check) {
    bool prime = true;
    for (int i = 2 ; i*i <= check ; i++) {
        if (check % i == 0) {
            prime = false;  
        }
    }
    return prime;
}

int main() {
    #ifndef LOCAL
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    #endif
    int a, b;
    cin >> a >> b;

    vector<int> sols;
    int out = false;
    for (int i1 = 0; i1 <= 9 ; i1++) {
        for (int i2 = 0; i2 <= 9 ; i2++) {
            for (int i3 = 0; i3 <= 9 ; i3++) {
                for (int i4 = 0; i4 <= 9 ; i4++) {
                    int num = i1 + i2*10 + i3*100 + \
                              i4*1'000 + \
                              i3*10'000 + i2*100'000 + i1*1'000'000;
                    int numb = i1 + i2*10 + i3*100 + \
                               i4*1'000 + i4*10'000 + \
                               i3*100'000 + i2*1'000'000 + i1*10'000'000;
                    if (i1 == 0) {
                        num /= 10;
                        numb /= 10;
                        if (i2 == 0) {
                            num /= 10;
                            numb /= 10;
                            if (i3 == 0) {
                                num /= 10;
                                numb /= 10;
                                if (i4 == 0) {
                                    continue;
                                }
                            }
                        }
                    }
                    if (num % 2 == 0) {
                        continue;
                    }
                    
                    if (num > b) {
                        out = true;
                        break;
                    }
                    if (num >= a && num <= b) {
                        if (isprime(num)) sols.push_back(num);
                    } if (numb >= a && numb <= b) {
                        if (isprime(numb)) sols.push_back(numb);
                    }
                }
                if (out) break;
            }
            if (out) break;
        }
        if (out) break;
    }
    sort(sols.begin(), sols.end());

    for (int i = 0; i < sols.size(); i++) {
        cout << sols[i] << endl;
    }
}