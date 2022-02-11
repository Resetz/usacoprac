#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> dp;
int n;
int doit(int r, int c) {
    cerr << dp.size() << " " << (r*(r-1))/2+c << " " << r << " " << c << endl;
    if (dp[(r*(r-1))/2+c] != -1) return dp[(r*(r-1))/2+c];
    if (r >= n) {
        dp[(r*(r-1))/2+c] = v[(r*(r-1))/2+c];
    } else {
        dp[(r*(r-1))/2+c] = v[(r*(r-1))/2+c] + max(doit(r+1,c),doit(r+1,c+1));
    }
    return dp[(r*(r-1))/2+c];
}

int main() {
    cin >> n;

    v = vector<int>((n*(n+1))/2+1, 0);
    dp = vector<int>((n*(n+1))/2+1, -1);
    for (int r = 1; r <= n; r++) {
        int pre = (r*(r-1))/2;
        for (int c = 1; c <= r; c++) {
            cin >> v[pre+c];
        }
    }

    cout << doit(1,1);
}