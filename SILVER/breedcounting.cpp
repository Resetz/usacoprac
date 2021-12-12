#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<int> h(n+1);
    vector<int> g(n+1);
    vector<int> j(n+1);

    vector<vector<int>> pf(3, vector<int>(n+1));
    pf[0][0] = 0;
    pf[1][0] = 0;
    pf[2][0] = 0;
    for (int i = 0 ; i < n ; i++) {
        int t;
        cin >> t;
        t--;
        for (int j = 0 ; j < 3 ; j++) {
            pf[j][i+1] = pf[j][i];
            if (j == t) {
                pf[j][i+1]++;
            }
        }
    }   

    for (int i = 0 ; i < q ; i++) {
        int f,t;
        cin >> f >> t;
        f--;
        for (int j = 0 ; j < 3; j++) {
            cout << pf[j][t] - pf[j][f];
            if (j != 2) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
}