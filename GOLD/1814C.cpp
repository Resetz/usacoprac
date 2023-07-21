#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int,int>> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.rbegin(), v.rend());
    vector<pair<int,int>> k;
    int l = 0;
    int ac = 0;
    int bc = 0;
    int t = 1;
    while (l < n) {
        //cout << "t " << t << endl;
        if (t % a == 0) {
            k.push_back({0,true});
            ac++;
            l++;
        }
        if (t % b == 0) {
            k.push_back({0,false});
            bc++;
            l++;
        }
        t++;
    }
    vector<int> aa;
    vector<int> ba;
    //cout << "here" << endl;
    for (int i = 0 ; i < n ; i++) {
        //cout << v[i].second << " " << v[i].first << endl;
        if (k[i].second) {
            aa.push_back(v[i].second+1);
        } else {
            ba.push_back(v[i].second+1);
        }
    }
    cout << aa.size() << " ";
    for (int i = 0 ; i < aa.size() ; i++) {
        cout << aa[i] << " ";
    }
    cout << endl;
    cout << ba.size() << " ";
    for (int j = 0 ; j < ba.size() ; j++) {
        cout << ba[j] << " ";
    }
    cout << endl;
    
}

int main() {
    int n;
    cin >> n; while (n--) solve();
}