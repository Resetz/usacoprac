#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    long long n, d;
    cin >> n >> d;
    vector<long long> v(n);
    long long tot = 0;
    for (long long i = 0 ; i < n ; i++) {
        cin >> v[i];
        tot += v[i];
    }
    sort(v.begin(), v.end());
    long long cur = 0;
    while (v[cur] == 0) {
        cur++;
    }
    long long sum = 0;
    for (long long i = 0 ; i < d ; i++) {
        long long a;
        cin >> a;

        cout << n- cur << " " << tot << endl;

        while (cur < n) {
            //cout << v[cur] << " " << sum << " " << a << endl;
            if (v[cur] - sum <= a) {
                tot -= v[cur] - sum;
                cur++;
            } else {
                break;
            }
        }
        sum += a;
        tot -= (n-cur) * a;

    }
}