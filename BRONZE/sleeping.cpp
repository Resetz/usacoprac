#include <iostream>
#include <vector>

using namespace std;

void solve() {
    unsigned long long sum = 0;
    unsigned long long n;
    cin >> n;
    vector<unsigned long long> v(n);
    
    for (unsigned long long i = 0; i < n ; i++) {
        cin >> v[i];
        sum += v[i];
    }

    bool s = true;
    for (unsigned long long i = 0 ; i < n ; i++) {
        if (v[i] != v[0]) {
            s = false;
        }
    }
    if (s) {
        cout << 0 << endl;
        return;
    }
    //cout << "done" << endl;

    unsigned long long current = 0;
    unsigned long long ans = n;
    unsigned long long elems = 0;
    for (unsigned long long i = 0; i < n ; i++) {
        current += v[i];
        elems++;
        if (current == 0 || v[i] == 0) continue;
        if (sum % current == 0) {
            //try
            //cout << "trying " << current << endl;
            bool good = true;
            unsigned long long cursum = 0;
            unsigned long long bst = elems-1;
            unsigned long long curelems = 0;
            for (unsigned long long j = i+1 ; j < n ; j++) {
                cursum += v[j];
                curelems++;
                //cout << cursum << " " << curelems;
                if (cursum == current) {
                    bst += curelems-1;
                    //cout << " + " << curelems-1;
                    curelems = cursum = 0;
                } else if (cursum > current) {
                    //cout << endl;
                    good = false; break;
                }
                //cout << endl;
            }
            if (cursum == current || (cursum == 0) ) {
                if (curelems > 0) {
                    bst += curelems;
                }
            } else {
                good = false;
            }
            if (good) {
                //cout << current << " results in " << bst << endl;
                ans = min(bst, ans);
            }
        }
    }
    ans = min(elems-1, ans);
    cout << ans << endl;
}
int main() {
    unsigned long long n;
    cin >> n;
    while (n--) solve();
}