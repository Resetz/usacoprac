#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


long long f(long long k) {
    return (k)*(k-1)*(k-2)/6;
}

int main() {
    long long n;
    cin >> n;

    cout << f(n-1)-4*f(n/2);
}