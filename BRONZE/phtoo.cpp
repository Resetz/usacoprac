#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> f(n);
    vector<int> t(n);
    vector<int> v(n);
    vector<int> k(n);

    for (int i = 0; i < n ; i++) {
        int k;
        cin >> v[i];
        v[i]--;
        f[v[i]] = i;
    }
    for (int i = 0; i < n ; i++) {
        cin >> k[i];
        k[i]--;
        t[k[i]] = i;
    }


    int ans = 0;
    for (int i = 0 ; i < n; i++) {
        //cout << endl;
        //cout << endl;
        int temp = k[i];
        if (v[i] != k[i]) {
            ans++;
            //cout <<" wow" << endl;
        }
        //cout << k[i]+1 << " " << f[k[i]]-1 << " " << i << endl;
        for (int j = f[k[i]]-1 ; j >= i ; j--) {
            
            v[j+1] = v[j];
            f[v[j]]++;

        }
        f[v[i]] = i;
        v[i] = temp;
    }
    cout << ans << endl;
   
}