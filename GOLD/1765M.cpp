#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    //long long is just a bigger integer
    long long  n;
    cin >> n;

    long long best = n*n;
    long long ans = 0;

    for (long long i = 1 ; i <= (long long)sqrt(n) ; i++) {

        //loop through all possible factors < sqrt(n)

        if (n % i == 0) {
            long long other = n - i;
            if ((other * i) / gcd(other, i) < best) {
                best = min((other * i) / gcd(other, i), best);
                ans = i;
            }

            //test other factor
            long long a = n/i;
            long long b = n-a;
            //0 is not a factor
            if (a == 0 || b == 0) continue;
            if ((a * b) / gcd(a, b) < best) {
                best = min((a * b) / gcd(a, b), best);
                ans = a;
            }
        } 
    }

    cout << ans << " " << n-ans << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}