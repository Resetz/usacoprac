// time-limit: 2000
// problem-url: https://codeforces.com/contest/1613/problem/C


#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>


using namespace std;

vector<unsigned long long> v;
unsigned long long n;
unsigned long long h;
bool go(unsigned long long k) {
    unsigned long long last = 0;
    bool countFirst = true;

    //qcheck
    long long done = 0;
    for (int i = 0; i < n ; i++) {

        if (i != 0) {
            done -= !countFirst;
            if (v[i] - last > k) {
                done += k;
                countFirst = true;
            } else {
                done += v[i] - last + 1;
                countFirst = false;
            }
        }

        last = v[i];
    }
    done -= !countFirst;
    done += k;
    //cout << k << " " << done << endl;
    if (done < h) {
        return false;
    } else {
        return true;
    }
}

void solve() {
    cin >> n >> h;

    v.resize(n);
    for (int i = 0; i < n ; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    unsigned long long high, mid, low;
    high = 0xffffffffffffffff;
    low = 0;
    unsigned long long ans = 0;
    while (high >= low) {
        mid = (high + low) / 2;
        if (go(mid)) {
            high = mid-1;
            ans = mid;
        } else {
            low = mid+1;
        }
    }
    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {solve();}
}