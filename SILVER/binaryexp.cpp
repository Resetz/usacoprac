#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;


unsigned long long exp(unsigned long long base, unsigned long long next, unsigned long long mod) {
    cout << next << endl;
    if (next == 1) return base % mod;
    unsigned long long save = exp(base, next/2, mod) % mod;
    if (next % 2 == 1) {
        return (base) % mod * (save * save) % mod;
    } else {
        return (save * save) % mod;
    }
}

unsigned long long exp_slow(unsigned long long base, unsigned long long next, unsigned long long mod) {
    unsigned long long ans = 1;
    for (int i = 0 ; i < next ; i++) {
        ans = (ans * base) % mod;
    }
    return ans;
}

int main() {
    auto start = high_resolution_clock::now();
    cout << exp_slow(47,100000000,3) << endl;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "time took: " << duration.count() << "ms" << endl;


    start = high_resolution_clock::now();
    cout << exp(47,1000000000,3) << endl;
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "time took: " << duration.count() << "ms" << endl;
}