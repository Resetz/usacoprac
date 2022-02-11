/*
ID: vincent97
TASK: barn1
LANG: C++                 
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    #ifndef LOCAL
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    #endif

    int n, m, c;
    cin >> n >> m >> c;
    vector<int> v;

    for (int i = 0 ; i < c; i++) {
        int num = 0;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());

    int first = v[0]-1;
    int len = m-v[c-1];
    bool last = false;
    vector<int> gaps;
    for (int i = 1 ; i < c ; i++) {
        gaps.push_back(v[i]-v[i-1]-1);
    }
    
    sort(gaps.rbegin(), gaps.rend());
    int ans = m;
    ans -= first;
    ans -= len;
    for (int i = 0 ; i < min((int)gaps.size(), n-1) ; i++) {
        ans -= gaps[i];
    }
    cout << ans << endl;
}