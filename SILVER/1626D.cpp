#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n ; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<int> pf;
    vector<int> pow2;
    int i;
    for (i = 1 ; i < n ; i*=2) {
        pow2.push_back(i);
    }
    i*=2;
    pow2.push_back(i);
    
    
    
    vector<int> pos;
    int prev = -1;
    int len = 0;
    for (int i = 0 ; i < n ; i++) {
        if (prev == v[i]) {
            len++;
        } else {
            pos.push_back(len);
            len = 0;
            prev = v[i];
        }
    }

    pos.push_back(len);

    pf.resize(pos.size()+1);

    for (int i = 0; i < pos.size(); i++) {
        pf[i+1] = pf[i] + pos[i];
    }

    for (int i = 0 ; i < pow2.size() ; i++) {
        vector<int>::iterator left = lower_bound(pf.begin(), pf.end(), pow2[i]);
        int left = v[left-v.begin()];
        for (int j = i+1; j < pow2.size() ; j++) {
            vector<int>::iterator right = lower_bound(left, pf.end(), pow2[j]);
            int right = v[right-v.begin()];
        }
    }

}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}