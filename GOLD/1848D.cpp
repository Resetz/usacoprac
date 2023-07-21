#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> pc;
vector<long long> pow2;

pair<long long,long long> val(long long x, long long y) {
    long long ans = y;
    long long sum = 0;
    int i = 0;
    long long cursum = y;
    y %= 10;
    while (x > 0) {
        if (x&1) {
            ans += pc[y][i];
            y = ans%10;

            sum += cursum * pow2[i] + pc[y][i];
            cursum += pc[y][i];
        }
        x >>= 1;
        i++;
    }
    return {ans, sum};
}

void solve() {
    int a,b;
    cin >> a >> b;
    long long high, low, ans;
    high = b;
    low = 0;
    ans = 0;
    while (high >= low) {
        long long mid = low + (high - low)/2;
        
        //go through sparse tree

        long long next = mid;
        pair<long long, long long> p1 = val(next,a);
        pair<long long, long long> p2 = val(next+1,a);
        if (p1.first*(b-mid) > p2.first*(b-(mid+1))) {
            ans = max(ans,p1.first*(b-(mid)));
            high = mid-1;
        } else {
            ans= max(ans,p2.first*(b-(mid+1)));
            low = mid+1;
        }
    }
    
    cout << ans << endl;
    
}

int main() {

    pc.resize(10, vector<long long>(32));
    // starting at digit i going 2^j steps
    for (int i = 0 ; i < 10 ; i++) {
        pc[i][0] = i;
    }
    for (int i = 1 ; i < 32 ; i++) {
        for (int j = 0 ; j < 10 ; j++) {
            pc[j][i] = pc[j][i-1] + pc[(j+pc[j][i-1])%10][i-1];
        }
    }
    pow2.resize(32);
    pow2[0] = 1;
    for (int i = 1 ; i < 30 ;i++) {
        pow2[i] = pow2[i-1]*2;
    }
    int t;
    cin >> t;
    while (t--) solve();
}