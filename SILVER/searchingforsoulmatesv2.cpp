#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void solve() {
    unsigned long long f, t;
    cin >> f>> t;

    //divide by 2;

    unsigned long long cur = f;
    unsigned long long ans = INT_MAX;
    int curadd = 0;
    int i = 0;
    unsigned long long nt = t;
    while (nt > 0) {
        int sec = 0;
        unsigned long long wow = nt;
        unsigned long long cur = f;
        while (cur > wow) {
            if (cur % 2L == 1) {
                sec++;
                cur++;
            }
            cur /= 2;
            sec++;
        }
        ans = min(sec+curadd+(wow-cur), ans);
        //cout << f << " to " << nt << " " << cur << " | " << sec  << " " << curadd << " " << (nt-cur) << " " << ans << endl;
        

        // div op on t -> mul on f
        if (nt % 2 == 1) {
            curadd++;
        }
        curadd++;
        nt/=2;
        i++;
    }
    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}